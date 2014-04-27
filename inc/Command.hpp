#ifndef COMMAND_HPP_
# define COMMAND_HPP_

# include "APizza.hpp"

class			Command
{
public:
  Command(const std::vector<APizza *> &pizzas);
  ~Command();

  bool			hasPizza(const APizza &pizza) const;
  bool			isFinished(void) const;

private:
  std::vector<APizza *>	_pizzas;
};

#endif /* !COMMAND_HPP_ */
