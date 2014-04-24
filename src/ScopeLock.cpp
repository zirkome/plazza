#include "ScopeLock.hpp"

ScopeLock::ScopeLock(IMutex<pthread_mutex_t>& mutex)
  : _mutex(mutex)
{
  _mutex.lock();
}

ScopeLock::~ScopeLock()
{
  _mutex.unlock();
}
