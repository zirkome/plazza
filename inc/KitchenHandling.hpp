#ifndef KITCHENHANDLING_HPP_INCLUDED
# define KITCHENHANDLING_HPP_INCLUDED

# include <iostream>

# include "ITask.hpp"
# include "NamedPipe.hpp"
# include "ThreadPool.hpp"

class KitchenHandling : public ITask
{
public:
  KitchenHandling(NamedPipe &in, NamedPipe &out);
  ~KitchenHandling();

  virtual void execute();

private:
  NamedPipe& _in;
  NamedPipe& _out;
};

#endif // KITCHENHANDLING_HPP_INCLUDED
