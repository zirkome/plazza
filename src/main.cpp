#include <iostream>
#include <exception>

#include "PThread.hpp"

class Task
{
private:
  char *_param;
public:
  Task(char *str) : _param(str)
  {
  }

  void operator()()
  {
    std::cout << _param << std::endl;
  }
};

int main(int argc, char *argv[])
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
	  PThread<Task> toto(lol);
	}
    }
  catch (const std::exception& e)
    {
      std::cerr << e.what() << std::endl;
    }
  return (0);
}
