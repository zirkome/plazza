#include <iostream>
#include <exception>
#include <unistd.h>

#include "ITask.hpp"
#include "PThread.hpp"
#include "PMutex.hpp"
#include "ProcUnix.hpp"

class Task : public ITask
{
private:
  char *_param;
public:
  Task(char *str) : _param(str)
  {
  }

  virtual void execute()
  {
    std::cout << _param << std::endl;
  }
};

int main(int argc, __attribute__((unused)) char *argv[])
{
  try
    {
      if (argc != 4)
        {
          std::cerr << "Invalid number of arguments" << std::endl;
          return (1);
        }
      for (int i = 0; i < argc; i++)
        {
          Task lol(argv[i]);
          ProcUnix l(&lol);
        }
    }
  catch (const std::exception& e)
    {
      std::cerr << e.what() << std::endl;
    }
  return (0);
}
