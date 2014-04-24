#ifndef PROCUNIX_HPP_INCLUDED
#define PROCUNIX_HPP_INCLUDED

#include "IProcess.hpp"

class ProcUnix : public IProcess
{
public:
  ProcUnix();
  virtual ~ProcUnix();

  template<typename T>
  virtual void createProcess(void (T::*call)(T& that), T& that);

  virtual State status() const;
  virtual void killProcess();
  virtual void waitProcess() const;

private:

};

#endif // PROCUNIX_HPP_INCLUDED
