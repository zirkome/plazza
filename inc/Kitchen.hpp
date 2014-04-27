#ifndef KITCHEN_H
# define KITCHEN_H

# include <string>

# include "IProcess.hpp"
# include "InNamedPipe.hpp"
# include "OutNamedPipe.hpp"

# include "KitchenHandling.hpp"

class Kitchen
{
public:
  Kitchen(const std::string& name, size_t nbCookers);
  virtual ~Kitchen();



private:
  InNamedPipe* _in;
  OutNamedPipe* _out;
  IProcess *_process;
};

#endif // KITCHEN_H
