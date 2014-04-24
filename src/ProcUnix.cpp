#include "ProcUnix.hpp"

ProcUnix::ProcUnix(ITask* f)
  : _routine(f), _state(THR_WAITING)
{
  _pid = fork();
  if (_pid == -1)
    throw std::runtime_error(std::string("fork ") + strerror(errno));
  if (_pid > 0)
    {
      _state = THR_ALIVE;
    }
  else
    {
      try
        {
          f->execute();
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
  join(NULL);
}

void ProcUnix::join(void** ret)
{
  int reur;

  (void)ret;
  if (_state != THR_ALIVE)
    return;
  if (waitpid(_pid, &reur, 0) < 0)
    throw std::runtime_error(std::string("process_wait") + strerror(errno));
  _state = THR_DEAD;
}
