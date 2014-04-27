#ifndef KITCHEN_H
# define KITCHEN_H

# include <string>

# include "IThread.hpp"
# include "IProcess.hpp"
# include "InNamedPipe.hpp"
# include "OutNamedPipe.hpp"

# include "KitchenHandling.hpp"

class Kitchen
{
public:
  Kitchen(const std::string& name, float cookMultiplier, size_t nbCookers, float stockRenewalTime);
  virtual ~Kitchen();

  void newOrder(APizza* pizza);

  std::vector<IThread::State> getStatus() const;

private:
  InNamedPipe* _in;
  OutNamedPipe* _out;
  IProcess *_process;
};

#endif // KITCHEN_H
