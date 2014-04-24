#ifndef _THREAD_H_
# define _THREAD_H_

# include <stdexcept>
# include <string>
# include <cstring>
# include <cerrno>

# include "ITask.hpp"
# include "IThread.hpp"

/*
 * Posix Thread C++ Encapsulation
 */
class PThread : public IThread
{
public:
  PThread(ITask *f) : _routine(f), _state(THR_WAITING), _exit(false)
  {
    if (pthread_create(&_thread, NULL, &PThread::handleThread, this) != 0)
      throw std::runtime_error(std::string("pthread_create") + strerror(errno));
    _state = THR_ALIVE;
  }

  virtual ~PThread()
  {
    setExit(true);
    join(NULL);
  }

public:
  virtual void join(void **retval)
  {
    if (pthread_join(_thread, retval) != 0)
      throw std::runtime_error(std::string("pthread_join") + strerror(errno));
    _state = THR_DEAD;
  }

  virtual State getState()
  {
    return _state;
  }

  virtual void setState(State state)
  {
    _state = state;
  }

  void setExit(bool exit)
  {
    _exit = exit;
  }

private:
  static void *handleThread(void *arg)
  {
    PThread* that = reinterpret_cast<PThread*>(arg);

    while (!that->getExit())
      {
	if (that->getState() == THR_ALIVE)
	  {
	    that->getRoutine()->execute();
	    that->setState(THR_WAITING);
	  }
      }
    return (NULL);
  }

  ITask *getRoutine()
  {
    return _routine;
  }

  bool getExit()
  {
    return _exit;
  }

private:
  ITask* _routine;
  pthread_t _thread;
  State	_state;
  bool _exit;
};

#endif /* _THREAD_H_ */
