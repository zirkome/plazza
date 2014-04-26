#include <sstream>

#include "Reception.hpp"
#include "PThread.hpp"

Reception::Reception(float cookMultiplier, size_t cookPerKitchen, float stockRenewalTime)
  : _time(1.0 / (stockRenewalTime / 1000.0)), _cookMultiplier(cookMultiplier),
    _cookPerKitchen(cookPerKitchen), _stockRenewalTime(stockRenewalTime), _KitchenCounter(0)
{
  std::stringstream tmp;

  _sdl = new PThread();
  _sdl->setTask(new Graphique(*this));
  tmp << _KitchenCounter;
  _kitchens.push_back(new Kitchen(tmp.str()));
  ++_KitchenCounter;
}

Reception::~Reception()
{
  delete _sdl;
  for (std::deque<Kitchen*>::iterator it = _kitchens.begin(), end = _kitchens.end(); it != end; ++it)
    {
      delete *it;
    }
}

void Reception::openPizza()
{
}
