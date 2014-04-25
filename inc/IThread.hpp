#ifndef _ITHREAD_H_
# define _ITHREAD_H_

# include "ITask.hpp"

class IThread
{
public:
  enum State
    {
      THR_WAITING,
      THR_ALIVE,
      THR_DEAD
    };

public:
  virtual ~IThread() {};

public:
  virtual void join(void** retval) = 0;
  virtual int cancel() const = 0;

  virtual ITask *getTask() const = 0;
  virtual void setTask(ITask *) = 0;

  virtual State getState() const = 0;
  virtual void setState(State state) = 0;
};

#endif /* _ITHREAD_H_ */
