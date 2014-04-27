#include <string>

#include "PThread.hpp"
#include "Cook.hpp"

#include "KitchenHandling.hpp"

KitchenHandling::KitchenHandling(InNamedPipe &in, OutNamedPipe &out, size_t nbCookers)
  : _in(in), _out(out), _nbCookers(nbCookers)
{
}

KitchenHandling::~KitchenHandling()
{

}

void KitchenHandling::execute()
{
  ThreadPool<PThread> cookers(_nbCookers);
  std::string line;

  while (true)
    {
      std::getline(_in, line);
      if (line == "STATUS")
        {
          _out <<  << std::endl;
        }
      else
        {
	  //cooker.queueTask(Cook(new APizza(commandePizza)));
        }
    }
}
