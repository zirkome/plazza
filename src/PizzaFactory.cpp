#include <iostream>

#include "APizza.hpp"
#include "Regina.hpp"
#include "Margarita.hpp"
#include "Americana.hpp"
#include "Fantasia.hpp"
#include "PizzaFactory.hpp"

APizza* PizzaFactory::newPizza(APizza::TypePizza type,
			       APizza::TaillePizza size)
{
  switch (type)
    {
    case APizza::Regina:
      return new Regina(size);
    case APizza::Margarita:
      return new Margarita(size);
    case APizza::Americaine:
      return new Americana(size);
    case APizza::Fantasia:
      return new Fantasia(size);
    }
  return NULL;
}
