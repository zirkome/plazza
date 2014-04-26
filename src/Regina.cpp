#include "Regina.hpp"

Regina::Regina(APizza::TaillePizza size)
  : APizza(APizza::Regina, size), _ingredients(5)
{
  _ingredients.push_back(Doe);
  _ingredients.push_back(Tomato);
  _ingredients.push_back(Gruyere);
  _ingredients.push_back(Ham);
  _ingredients.push_back(Mushrooms);
}

Regina::~Regina()
{
}

const std::vector<APizza::Ingredients>& Regina::getIngredients() const
{
  return _ingredients;
}
