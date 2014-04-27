#include <list>

#include "Command.hpp"

Command::Command(const std::list<APizza *> &pizzas)
  : _pizzas(pizzas)
{
}

Command::~Command()
{
}

bool	Command::hasPizza(const APizza &pizza) const
{
  for (std::list<APizza *>::const_iterator it = _pizzas.begin(),
	 end = _pizzas.end(); it != end; ++it)
    {
      if ((*it)->getType() == pizza.getType() &&
	  (*it)->getSize() == pizza.getSize() &&
	  (*it)->isDone() == false)
	{
	  (*it)->setDone(true);
	  return (true);
	}
    }
  return (false);
}

bool	Command::isFinished(void) const
{
  for (std::list<APizza *>::const_iterator it = _pizzas.begin(),
	 end = _pizzas.end(); it != end; ++it)
    {
      if ((*it)->isDone() == false)
	return (false);
    }
  return (true);
}
