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

APizza* PizzaFactory::unpackPizza(std::string const &toDeserialize)
{
  std::istringstream iss(toDeserialize);
  int type;
  int size;

  iss >> type >> size;
  return (PizzaFactory::newPizza((APizza::TypePizza) type, (APizza::TaillePizza) size));
}

std::string& PizzaFactory::packPizza(APizza const &toSerialize)
{
  std::ostringstream oss;

  oss << toSerialize.getType() << " " << toSerialize.getSize();
  return (* new std::string(oss.str()));
}
