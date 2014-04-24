#ifndef _MUTEX_H_
# define _MUTEX_H_

# include <pthread.h>

# include "IMutex.hpp"

/*
 * Posix Mutex C++ encapsulation
 */
class PMutex : public IMutex<pthread_mutex_t>
{
public:
  PMutex(const pthread_mutexattr_t *attr = NULL);
  virtual ~PMutex();

public:
  virtual pthread_mutex_t *getMutex();
  virtual void lock();
  virtual void unlock();
  virtual void trylock();

private:
  pthread_mutex_t _mutex;
};

#endif /* _MUTEX_H_ */
