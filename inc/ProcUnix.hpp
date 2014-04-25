#ifndef PROCUNIX_HPP_INCLUDED
# define PROCUNIX_HPP_INCLUDED

# include <stdexcept>
# include <string>
# include <cstring>
# include <cerrno>
# include <cstdlib>

# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>


# include "ITask.hpp"
# include "IProcess.hpp"

class ProcUnix : public IProcess
{
public:
  ProcUnix(ITask &f);
  virtual ~ProcUnix();

  virtual void join(void** ret);

  virtual State getState() {return _state;};
  virtual void setState(State state) {_state = state;};

private:
  ITask& _routine;
  pid_t _pid;
  State _state;
};

#endif // PROCUNIX_HPP_INCLUDED
