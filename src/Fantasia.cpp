#include "Fantasia.hpp"

Fantasia::Fantasia(APizza::TaillePizza size)
  : APizza(APizza::Fantasia, size), _ingredients(5)
{
  _ingredients.push_back(Doe);
  _ingredients.push_back(Tomato);
  _ingredients.push_back(Gruyere);
  _ingredients.push_back(Ham);
  _ingredients.push_back(Mushrooms);
}

Fantasia::~Fantasia()
{
}

const std::vector<APizza::Ingredients>& Fantasia::getIngredients() const
{
  return _ingredients;
}
