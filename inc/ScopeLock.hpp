#ifndef _SCOPELOCK_H_
# define _SCOPELOCK_H_

# include <pthread.h>

# include "IMutex.hpp"

class ScopeLock
{
public:
  ScopeLock(IMutex<pthread_mutex_t>& mutex);
  virtual ~ScopeLock();

private:
  IMutex<pthread_mutex_t>& _mutex;
};

#endif /* _SCOPELOCK_H_ */
