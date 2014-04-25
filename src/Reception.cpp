#include "Reception.hpp"

Reception::Reception(float cookMultiplier, size_t cookPerKitchen, float stockRenewalTime)
  : _time(1.0 / (stockRenewalTime / 1000.0)), _cookMultiplier(cookMultiplier),
    _cookPerKitchen(cookPerKitchen), _stockRenewalTime(stockRenewalTime)
{
  _kitchens.push_back(new Kitchen());
}

Reception::~Reception()
{
  for (std::deque<Kitchen*>::iterator it = _kitchens.begin(), end = _kitchens.end(); it != end; ++it)
    {
      delete *it;
    }
}
