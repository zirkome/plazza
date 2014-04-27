#ifndef KITCHENHANDLING_HPP_INCLUDED
# define KITCHENHANDLING_HPP_INCLUDED

# include <iostream>

# include "ITask.hpp"
# include "InNamedPipe.hpp"
# include "OutNamedPipe.hpp"
# include "ThreadPool.hpp"

class KitchenHandling : public ITask
{
public:
  KitchenHandling(InNamedPipe &in, OutNamedPipe &out, size_t nbCookers);
  ~KitchenHandling();

  virtual void execute();

private:
  InNamedPipe& _in;
  OutNamedPipe& _out;
  size_t _nbCookers;
};

#endif // KITCHENHANDLING_HPP_INCLUDED
