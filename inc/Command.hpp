#ifndef COMMAND_HPP_
# define COMMAND_HPP_

# include <list>

# include "APizza.hpp"

class			Command
{
public:
  Command(const std::list<APizza *> &pizzas);
  ~Command();

  bool			hasPizza(const APizza &pizza) const;
  bool			isFinished(void) const;

  const std::list<APizza*>& getPizzas() const {return _pizzas;};

private:
  std::list<APizza *>	_pizzas;
};

#endif /* !COMMAND_HPP_ */
