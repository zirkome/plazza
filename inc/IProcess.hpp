#ifndef IPROCESS_HPP_INCLUDED
#define IPROCESS_HPP_INCLUDED

class IProcess
{
public:
  enum State
  {
    PROC_ALIVE,
    PROC_DEAD
  };

  virtual ~IProcess() {};

  virtual void wait() = 0;

  virtual State getState() const = 0;
};

#endif // IPROCESS_HPP_INCLUDED
