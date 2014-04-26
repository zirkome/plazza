#ifndef KITCHEN_H
# define KITCHEN_H

# include <string>

# include "IProcess.hpp"
# include "NamedPipe.hpp"

# include "KitchenHandling.hpp"

class Kitchen
{
public:
  Kitchen(const std::string& name, size_t nbCookers);
  virtual ~Kitchen();

private:
  NamedPipe _in;
  NamedPipe _out;
  IProcess *_process;
};

#endif // KITCHEN_H
