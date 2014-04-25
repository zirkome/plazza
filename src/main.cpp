#include <iostream>
#include <exception>
#include <unistd.h>

#include "ITask.hpp"
#include "PThread.hpp"
#include "PMutex.hpp"
#include "ProcUnix.hpp"
#include "ThreadPool.hpp"
#include "TimeHandling.hpp"

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
    std::cout.flush();
  }
};

int main(int argc, __attribute__((unused)) char *argv[])
{
  try
    {
    	TimeHandler time(1.0 / 5.0);

      if (argc != 4)
        {
          std::cerr << "Invalid number of arguments" << std::endl;
          return (1);
        }
      std::vector<ITask*> task;
      for (int i = 0; i < 52; i++)
        {
          task.push_back(new Task("sdf"));
        }
      ThreadPool<PThread> pol(task);
    }
  catch (const std::exception& e)
    {
      std::cerr << e.what() << std::endl;
    }
  return (0);
}
