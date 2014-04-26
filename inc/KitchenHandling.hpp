#ifndef KITCHENHANDLING_HPP_INCLUDED
# define KITCHENHANDLING_HPP_INCLUDED

# include <iostream>
# include <deque>

# include "ITask.hpp"
# include "NamedPipe.hpp"
# include "ThreadPool.hpp"
# include "Cook.hpp"

class KitchenHandling : public ITask
{
public:
  KitchenHandling(INamedPipe &in, INamedPipe &out, size_t nbCookers);
  ~KitchenHandling();

  virtual void execute();

private:
  INamedPipe& _in;
  INamedPipe& _out;
  size_t _nbCookers;
};

#endif // KITCHENHANDLING_HPP_INCLUDED
