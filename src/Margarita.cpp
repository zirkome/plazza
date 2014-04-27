#include "Margarita.hpp"

Margarita::Margarita(APizza::TaillePizza size)
  : APizza(APizza::Margarita, size), _ingredients(5)
{
  _ingredients.push_back(Doe);
  _ingredients.push_back(Tomato);
  _ingredients.push_back(Gruyere);
  _ingredients.push_back(Ham);
  _ingredients.push_back(Mushrooms);
}

Margarita::~Margarita()
{
}

const std::vector<APizza::Ingredients>& Margarita::getIngredients() const
{
  return _ingredients;
}
