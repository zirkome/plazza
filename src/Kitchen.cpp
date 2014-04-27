#include "ProcUnix.hpp"
#include "InNamedPipe.hpp"
#include "OutNamedPipe.hpp"

#include "Kitchen.hpp"

Kitchen::Kitchen(const std::string& name, size_t nbCookers)
  : _process(NULL)
{
  _in = new InNamedPipe(std::string("/tmp/kitin") + name);
  _out = new OutNamedPipe(std::string("/tmp/kitout") + name);

  KitchenHandling *tmp = new KitchenHandling(*_in, *_out, nbCookers);
  _process = new ProcUnix(*tmp);
  delete tmp;
}

Kitchen::~Kitchen()
{
  delete _in;
  delete _out;
  delete _process;
}
