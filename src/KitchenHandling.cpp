#include <string>
#include <iostream>

#include "Cook.hpp"

#include "KitchenHandling.hpp"

KitchenHandling::KitchenHandling(const std::string& inName, const std::string& outName, size_t nbCookers)
  : _inName(inName), _outName(outName), _nbCookers(nbCookers)
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

  while (std::getline(_in->getStream(), line))
    {
      if (line == "STATUS")
        _out->getStream() << cookerState(cookers) << std::endl;
      else
        {
          //tmpPizza = factory.unpack(line);
          //cooker.queueTask(Cook(tmpPizza));
        }
    }
  delete _in;
  delete _out;
}
