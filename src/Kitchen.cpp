#include "ProcUnix.hpp"
# include "NamedPipe.hpp"

#include "Kitchen.hpp"

Kitchen::Kitchen(const std::string& name, size_t nbCookers)
  : _process(NULL)
{
  _in = new NamedPipe(std::string("/tmp/kitin") + name);
  _out = new NamedPipe(std::string("/tmp/kitout") + name);

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
