#include "ProcUnix.hpp"

#include "Kitchen.hpp"

Kitchen::Kitchen(const std::string& name)
  : _in(std::string("/tmp/kitin") + name), _out(std::string("/tmp/kitout") + name),
    _process(NULL)
{
  KitchenHandling *tmp = new KitchenHandling(_in, _out);
  _process = new ProcUnix(*tmp);
  delete tmp;
}

Kitchen::~Kitchen()
{
  delete _process;
}
