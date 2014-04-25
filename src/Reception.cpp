#include "Reception.hpp"

Reception::Reception(float cookMultiplier, size_t cookPerKitchen, float stockRenewalTime)
  : _time(1.0 / (stockRenewalTime / 1000.0)), _cookMultiplier(cookMultiplier),
    _cookPerKitchen(cookPerKitchen), _stockRenewalTime(stockRenewalTime)
{
}

Reception::~Reception()
{

}
