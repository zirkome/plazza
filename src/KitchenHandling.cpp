#include "PThread.hpp"

#include "Cook.hpp"

#include "KitchenHandling.hpp"

KitchenHandling::KitchenHandling(INamedPipe &in, INamedPipe &out, size_t nbCookers)
  : _in(in), _out(out), _nbCookers(nbCookers)
{
}

KitchenHandling::~KitchenHandling()
{

}

void KitchenHandling::execute()
{
  ThreadPool<PThread> cookers(_nbCookers);

  while (true)
    {
//read
//if a command
//cooker.queueTask(Cook(new APizza(commandePizza)));
//else if status poll
//write status info

    }
}
