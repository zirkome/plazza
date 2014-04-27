#ifndef _PIZZAFACTORY_H_
# define _PIZZAFACTORY_H_

# include <list>
# include <sstream>

# include "APizza.hpp"

class PizzaFactory
{
public:
  static APizza* newPizza(APizza::TypePizza type,
			  APizza::TaillePizza size);

  static APizza* unpackPizza(std::string const &toDeserialize);
  static std::string& packPizza(APizza const &toSeriale);
};

#endif /* _PIZZAFACTORY_H_ */
