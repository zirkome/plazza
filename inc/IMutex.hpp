#ifndef _IMUTEX_H_
# define _IMUTEX_H_

template <typename T>
class IMutex
{
public:
  virtual ~IMutex() {};

public:
  virtual T *getMutex() = 0;
  virtual void lock() = 0;
  virtual void unlock() = 0;
  virtual void trylock() = 0;
};

#endif /* _IMUTEX_H_ */
