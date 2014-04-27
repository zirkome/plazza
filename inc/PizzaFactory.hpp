#ifndef _PIZZAFACTORY_H_
# define _PIZZAFACTORY_H_

# include <list>

# include "APizza.hpp"

class PizzaFactory
{
public:
  static APizza* newPizza(APizza::TypePizza type,
			  APizza::TaillePizza size);
};

#endif /* _PIZZAFACTORY_H_ */
