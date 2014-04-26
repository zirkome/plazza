#include "ProcUnix.hpp"

#include <iostream>
ProcUnix::ProcUnix(ITask &f)
  : _routine(f), _state(PROC_DEAD)
{
  _pid = fork();
  if (_pid == -1)
    throw std::runtime_error(std::string("fork ") + strerror(errno));
  if (_pid > 0)
    {
      _state = PROC_ALIVE;
    }
  else
    {
      try
        {
          f.execute();
        }
      catch (std::exception& e)
        {
          exit(1);
        }
      exit(0);
    }
}

ProcUnix::~ProcUnix()
{
  wait();
}

void ProcUnix::wait()
{
  int reur;

  if (_state != PROC_ALIVE)
    return;
  if (waitpid(_pid, &reur, 0) < 0)
    throw std::runtime_error(std::string("process_wait") + strerror(errno));
  _state = PROC_DEAD;
}
