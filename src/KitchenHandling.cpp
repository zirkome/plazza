#include "PThread.hpp"

#include "Cook.hpp"

#include "KitchenHandling.hpp"

KitchenHandling::KitchenHandling(NamedPipe &in, NamedPipe &out, size_t nbCookers)
  : _in(in), _out(out), _nbCookers(nbCookers)
{

}

KitchenHandling::~KitchenHandling()
{

}

void KitchenHandling::execute()
{
  ThreadPool<PThread> cookers(_nbCookers);

  std::cout << "Hello I'm a kitchen and I'm magic !!" << std::endl;

  cookers.queueTask(new Cook);
  cookers.queueTask(new Cook);
}
