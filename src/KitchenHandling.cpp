#include <string>
#include <iostream>

#include "Cook.hpp"

#include "KitchenHandling.hpp"

KitchenHandling::KitchenHandling(const std::string& inName, const std::string& outName, float cookMultiplier, size_t nbCookers, float stockRenewalTime)
  : _inName(inName), _outName(outName), _cookMultiplier(cookMultiplier), _nbCookers(nbCookers), _stockRenewalTime(stockRenewalTime)
{
}

KitchenHandling::~KitchenHandling()
{
}

std::string KitchenHandling::cookerState(const ThreadPool<PThread>& cookers) const
{
  std::string threadStatus;
  std::vector<IThread::State> stats = cookers.threadStatus();
  for (size_t i = 0; i < stats.size(); ++i)
    {
      IThread::State status = stats[i];
      threadStatus += std::string((status == IThread::THR_ALIVE) ? "THR_ALIVE"
                                  : (status == IThread::THR_DEAD) ? "THR_DEAD"
                                  : (status == IThread::THR_WAITING) ? "THR_WAITING" : "") + " ";
    }
  return threadStatus;
}

void KitchenHandling::execute()
{
  ThreadPool<PThread> cookers(_nbCookers);
  std::string line;
  _out = new OutNamedPipe(_outName);
  _in = new InNamedPipe(_inName);
  APizza* tmpPizza;

  while (std::getline(_in->getStream(), line))
    {
      if (line == "STATUS")
        _out->getStream() << cookerState(cookers) << std::endl;
      else
        {
          tmpPizza = PizzaFactory::unpackPizza(line);
          cookers.queueTask(new Cook(*tmpPizza));
        }
      cookers.executeQueuedTask();
    }
  delete _in;
  delete _out;
}
