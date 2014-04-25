#ifndef THREADPOOL_HPP_INCLUDED
# define THREADPOOL_HPP_INCLUDED

# include <vector>

# include "IThread.hpp"
#include "ITask.hpp"

template<typename T>
class ThreadPool
{
public:

  ThreadPool(const std::vector<ITask*>& task)
  {
    _pool.reserve(task.size());
    int i = 0;
    for (std::vector<ITask*>::const_iterator it = task.begin(), end = task.end(); it != end; ++it)
      {
        _pool[i] = new T(*it);
      }
  };

  ~ThreadPool()
  {
    for (std::vector<IThread*>::iterator it = _pool.begin(), end = _pool.end(); it != end; ++it)
      {
        delete *it;
      }
  };

private:
  std::vector<ITask*> _task;
  std::vector<IThread*> _pool;
};

#endif // THREADPOOL_HPP_INCLUDED
