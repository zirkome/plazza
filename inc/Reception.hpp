#ifndef RECEPTION_HPP_INCLUDED
# define RECEPTION_HPP_INCLUDED

# include <deque>
# include <iterator>

class Reception;

# include "Graphique.hpp"

# include "Kitchen.hpp"
# include "TimeHandling.hpp"

class Reception
{
public:
  Reception(float cookMultiplier, size_t cookPerKitchen, float stockRenewalTime);
  ~Reception();

  void openPizza();

private:
  TimeHandler _time;

  float _cookMultiplier;
  size_t _cookPerKitchen;
  float _stockRenewalTime;

  int _KitchenCounter;
  IThread *_sdl;
  std::deque<Kitchen*> _kitchens;
};

#endif // RECEPTION_HPP_INCLUDED
