#ifndef KITCHENHANDLING_HPP_INCLUDED
# define KITCHENHANDLING_HPP_INCLUDED

# include <iostream>

# include "ITask.hpp"
# include "NamedPipe.hpp"
# include "ThreadPool.hpp"

class KitchenHandling : public ITask
{
public:
  KitchenHandling(NamedPipe &in, NamedPipe &out, size_t nbCookers);
  ~KitchenHandling();

  virtual void execute();

private:
  NamedPipe& _in;
  NamedPipe& _out;
  size_t _nbCookers;
};

#endif // KITCHENHANDLING_HPP_INCLUDED
