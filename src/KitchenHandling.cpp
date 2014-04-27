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
      //read a command
      //write status info
    }
}
