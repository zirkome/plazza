#include "Reserve.hpp"

Reserve::Reserve()
{
  _mutex = new PMutex();
  _ingredients[APizza::Doe] = 5;
  _ingredients[APizza::Tomato] = 5;
  _ingredients[APizza::Gruyere] = 5;
  _ingredients[APizza::Ham] = 5;
  _ingredients[APizza::Mushrooms] = 5;
  _ingredients[APizza::Steak] = 5;
  _ingredients[APizza::Eggplant] = 5;
  _ingredients[APizza::GoatCheese] = 5;
  _ingredients[APizza::ChiefLove] = 5;
}

Reserve::~Reserve()
{
  delete _mutex;
}

bool Reserve::consume(const APizza& pizza)
{
  const std::vector<APizza::Ingredients>& ingr = pizza.getIngredients();
  bool ok = true;

  for (std::vector<APizza::Ingredients>::const_iterator it = ingr.begin(), end = ingr.end();
       it != end; ++it)
    {
      if (!consume((*it)))
        ok = false;
    }
  return ok;
}

bool Reserve::consume(APizza::Ingredients ingr)
{
  ScopeLock sl(*_mutex);
  if (_ingredients[ingr] > 0)
    --_ingredients[ingr];
  else
    return false;
  return true;
}

void Reserve::regenerate()
{
  ScopeLock sl(*_mutex);
  for (std::map<APizza::Ingredients, size_t>::iterator it = _ingredients.begin();
       it != _ingredients.end(); ++it)
    {
      ++it->second;
    }
}
