#ifndef RECEPTION_HPP_INCLUDED
#define RECEPTION_HPP_INCLUDED

#include "TimeHandling.hpp"

class Reception
{
public:
  Reception(float cookMultiplier, size_t cookPerKitchen, float stockRenewalTime);
  ~Reception();

private:
  TimeHandler _time;

  float _cookMultiplier;
  size_t _cookPerKitchen;
  float _stockRenewalTime;
};

#endif // RECEPTION_HPP_INCLUDED
