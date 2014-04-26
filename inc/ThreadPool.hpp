#ifndef THREADPOOL_HPP_INCLUDED
# define THREADPOOL_HPP_INCLUDED

# include <vector>
# include <list>

# include "IThread.hpp"
#include "ITask.hpp"

template<typename T>
class ThreadPool
{
public:

  ThreadPool(size_t nbWorkers)
  {
    _pool.reserve(nbWorkers);
    for (int i = 0; i < nbWorkers; ++i)
      _pool.push_back(new T());
  };

  ~ThreadPool()
  {
    for (std::vector<IThread*>::iterator it = _pool.begin(), end = _pool.end();
         it != end; ++it)
      {
        delete *it;
      }
  };

  void queueTask(ITask *task)
  {
    ITask *tmpTask;

    _tasks.push_back(task);
    for (std::vector<IThread*>::const_iterator it = _pool.begin(), end = _pool.end();
         it != end && _tasks.size() > 0; ++it)
      {
        if ((*it)->getState() == IThread::THR_WAITING)
          {
            tmpTask = _tasks.front();
            (*it)->setTask(tmpTask);
            _tasks.pop_front();
          }
      }
  };

  bool allWorkerBusy() const
  {
    for (std::vector<IThread*>::const_iterator it = _pool.begin(), end = _pool.end();
         it != end; ++it)
      {
        if ((*it)->getState() == IThread::THR_WAITING)
          return false;
      }
    return true;
  };

private:
  std::list<ITask*> _tasks;
  std::vector<IThread*> _pool;
};

#endif // THREADPOOL_HPP_INCLUDED
