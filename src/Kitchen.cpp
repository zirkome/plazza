#include "ProcUnix.hpp"
#include "InNamedPipe.hpp"
#include "OutNamedPipe.hpp"

#include "Kitchen.hpp"

Kitchen::Kitchen(const std::string& name, size_t nbCookers)
  : _process(NULL)
{
  std::string inName = std::string("/tmp/kitin") + name;
  std::string outName = std::string("/tmp/kitout") + name;

  KitchenHandling *tmp = new KitchenHandling(outName, inName, nbCookers);
  _process = new ProcUnix(*tmp);
  _in = new InNamedPipe(inName);
  _out = new OutNamedPipe(outName);
  delete tmp;
}

Kitchen::~Kitchen()
{
  delete _in;
  delete _out;
  delete _process;
}

std::vector<IThread::State> Kitchen::getStatus() const
{
  _out->getStream() << "STATUS" << std::endl;
  std::string status;

  std::getline(_in->getStream(), status);
  std::cout << status << std::endl;

  return std::vector<IThread::State>();
}
