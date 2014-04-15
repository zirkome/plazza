#ifndef _THREAD_H_
# define _THREAD_H_

# include <stdexcept>
# include <string>
# include <cstring>
# include <cerrno>

# include "IThread.hpp"

/*
 * Posix Thread C++ Encapsulation
 */
template <class T>
class PThread : public IThread
{
public:
  PThread(T& f) : _routine(f), _state(THR_WAITING)
  {
    if (pthread_create(&_thread, NULL, &PThread::handleThread, this) != 0)
      throw std::runtime_error(std::string("pthread_create") + strerror(errno));
    _state = THR_ALIVE;
  }

  virtual ~PThread()
  {
    join(NULL);
  }

public:

  virtual void join(void **retval)
  {
    if (getState() != IThread::THR_ALIVE)
      return;
    if (pthread_join(_thread, retval) != 0)
      throw std::runtime_error(std::string("pthread_join") + strerror(errno));
    _state = THR_DEAD;
  }

  virtual State getState()
  {
    return _state;
  }

private:
  static void *handleThread(void *arg)
  {
    PThread* that = reinterpret_cast<PThread*>(arg);

    that->getRoutine()();
    return (NULL);
  }

  T& getRoutine()
  {
    return _routine;
  }

private:
  T& _routine;
  pthread_t _thread;
  State	_state;
};

#endif /* _THREAD_H_ */
