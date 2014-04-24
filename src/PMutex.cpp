#include <stdexcept>

#include "PMutex.hpp"

PMutex::PMutex(const pthread_mutexattr_t *attr)
{
  if (pthread_mutex_init(&_mutex, attr) != 0)
    throw std::runtime_error("pthread_mutex_init");
}

PMutex::~PMutex()
{
  if (pthread_mutex_destroy(&_mutex) != 0)
    throw std::runtime_error("pthread_mutex_destroy");
}

pthread_mutex_t *PMutex::getMutex()
{
  return &_mutex;
}

void PMutex::lock()
{
  if (pthread_mutex_lock(&_mutex) != 0)
    throw std::runtime_error("pthread_mutex_lock");
}

void PMutex::unlock()
{
  if (pthread_mutex_unlock(&_mutex) != 0)
    throw std::runtime_error("pthread_mutex_unlock");
}

void PMutex::trylock()
{
  if (pthread_mutex_trylock(&_mutex) != 0)
    throw std::runtime_error("pthread_mutex_trylock");
}
