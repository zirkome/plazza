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
    for (std::vector<IThread*>::iterator it = _pool.begin(), end = _pool.end();
         it != end; ++it)
      (*it) = new T();
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
         it != end; ++it)
      {
        if ((*it)->getState() == IThread::THR_WAITING)
          {
            tmpTask = _tasks.front();
            _tasks.pop_front();
            (*it)->setTask(tmpTask);
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
