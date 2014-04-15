#ifndef _ITHREAD_H_
# define _ITHREAD_H_

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
  virtual State getState() = 0;
};

#endif /* _ITHREAD_H_ */
