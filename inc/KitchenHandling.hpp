#ifndef KITCHENHANDLING_HPP_INCLUDED
# define KITCHENHANDLING_HPP_INCLUDED

# include <iostream>
# include <deque>

# include "ITask.hpp"
# include "InNamedPipe.hpp"
# include "OutNamedPipe.hpp"
# include "ThreadPool.hpp"
# include "Cook.hpp"

class KitchenHandling : public ITask
{
public:
  KitchenHandling(const std::string& inName, const std::string& outName, size_t nbCookers);
  ~KitchenHandling();

  virtual void execute();

private:
  std::string cookerState() const;

private:
  std::string _inName;
  std::string _outName;
  InNamedPipe* _in;
  OutNamedPipe* _out;
  size_t _nbCookers;
};

#endif // KITCHENHANDLING_HPP_INCLUDED
