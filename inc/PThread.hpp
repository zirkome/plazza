#ifndef _THREAD_H_
# define _THREAD_H_

# include <stdexcept>
# include <string>
# include <cstring>
# include <cerrno>

# include "ITask.hpp"
# include "IThread.hpp"
# include "PMutex.hpp"
# include "PCondVar.hpp"

/*
 * Posix Thread C++ Encapsulation
 */
class PThread : public IThread
{
private:
  ITask* _task;
  PMutex _mutex;
  PCondVar _cv;
  pthread_t _thread;
  State	_state;

public:
  PThread()
    : _task(NULL), _cv(_mutex), _state(THR_WAITING)
  {
    if (pthread_create(&_thread, NULL, &PThread::handleThread, this) != 0)
      throw std::runtime_error(std::string("pthread_create") + strerror(errno));
  }

  virtual ~PThread()
  {
    _state = THR_DEAD;
    _cv.notify();
    join(NULL);
  }

public:
  virtual void join(void **retval)
  {
    if (pthread_join(_thread, retval) != 0)
      throw std::runtime_error(std::string("pthread_join") + strerror(errno));
    _state = THR_DEAD;
  }

  int setCancelModeAsynchronous() const
  {
    int status = pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, 0);
    if (status != 0) return status;

    return pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, 0);
  }

  virtual int cancel() const
  {
    int status = pthread_cancel(_thread);
    return status;
  }

  virtual State getState()  const
  {
    return _state;
  }

  virtual void setState(State state)
  {
    _state = state;
  }

  virtual ITask *getTask()  const
  {
    return _task;
  }

  //TODO
  // if (task == NULL)
  //   throw ThreadException("The task can't be null.");
  virtual void setTask(ITask *task)
  {
    _task = task;
    _state = THR_ALIVE;
    _cv.notify();
  }

private:
  PCondVar& getCondVar()
  {
    return _cv;
  }

private:
  static void *handleThread(void *arg)
  {
    PThread* that = reinterpret_cast<PThread*>(arg);

    while (true)
      {
        while (that->getState() != THR_DEAD && that->getTask() == NULL)
          that->getCondVar().wait();

        if (that->getState() == THR_DEAD)
          return NULL;

        that->getTask()->execute();
        that->setState(THR_WAITING);
        that->setTask(NULL);
      }
    return NULL;
  }
};

#endif /* _THREAD_H_ */
