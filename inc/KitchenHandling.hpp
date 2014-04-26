#ifndef KITCHENHANDLING_HPP_INCLUDED
# define KITCHENHANDLING_HPP_INCLUDED

# include <iostream>

# include "ITask.hpp"
# include "NamedPipe.hpp"
# include "ThreadPool.hpp"

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

  //std::deque<Cook> _furnaces;
};

#endif // KITCHENHANDLING_HPP_INCLUDED
