#ifndef KITCHEN_H
# define KITCHEN_H

# include <string>

# include "IProcess.hpp"
# include "INamedPipe.hpp"

# include "KitchenHandling.hpp"

class Kitchen
{
public:
  Kitchen(const std::string& name, size_t nbCookers);
  virtual ~Kitchen();



private:
  INamedPipe* _in;
  INamedPipe* _out;
  IProcess *_process;
};

#endif // KITCHEN_H
