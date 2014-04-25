#include "KitchenHandling.hpp"

KitchenHandling::KitchenHandling(NamedPipe &in, NamedPipe &out)
  : _in(in), _out(out)
{

}

KitchenHandling::~KitchenHandling()
{

}

void KitchenHandling::execute()
{
  std::cout << "Hello I'm a kitchen and I'm magic !!" << std::endl;
}
