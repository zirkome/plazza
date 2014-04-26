#include "Americana.hpp"

Americana::Americana(APizza::TaillePizza size)
  : APizza(APizza::Americaine, size), _ingredients(5)
{
  _ingredients.push_back(Doe);
  _ingredients.push_back(Tomato);
  _ingredients.push_back(Gruyere);
  _ingredients.push_back(Ham);
  _ingredients.push_back(Mushrooms);
}

Americana::~Americana()
{
}

const std::vector<APizza::Ingredients>& Americana::getIngredients() const
{
  return _ingredients;
}
