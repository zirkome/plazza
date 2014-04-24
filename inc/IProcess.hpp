#ifndef IPROCESS_HPP_INCLUDED
#define IPROCESS_HPP_INCLUDED

class IProcess
{
public:
  enum State
  {
    RUNNING,
    NOTRUNNING,
    PAUSED
  };

  virtual ~IProcess() {};

  virtual void createProcess(void (T::*)(T& that), T& that) = 0;

  virtual State status() const = 0;
  virtual void killProcess() = 0;
  virtual void waitProcess() const = 0;
};

#endif // IPROCESS_HPP_INCLUDED
