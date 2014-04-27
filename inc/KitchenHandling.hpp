#ifndef KITCHENHANDLING_HPP_INCLUDED
# define KITCHENHANDLING_HPP_INCLUDED

# include <iostream>
# include <deque>

# include "ITask.hpp"
# include "InNamedPipe.hpp"
# include "OutNamedPipe.hpp"
# include "ThreadPool.hpp"
# include "Cook.hpp"
# include "PThread.hpp"
# include "APizza.hpp"
# include "PizzaFactory.hpp"
# include "Reserve.hpp"

class KitchenHandling : public ITask
{
public:
  KitchenHandling(const std::string& inName, const std::string& outName, float cookMultiplier, size_t nbCookers, float stockRenewalTime);
  ~KitchenHandling();

  virtual void execute();

private:
  std::string cookerState(const ThreadPool<PThread>& cookers) const;

private:
  std::string _inName;
  std::string _outName;
  InNamedPipe* _in;
  OutNamedPipe* _out;
  Reserve res;

  float _cookMultiplier;
  size_t _nbCookers;
  float _stockRenewalTime;
};

#endif // KITCHENHANDLING_HPP_INCLUDED
