#include "PThread.hpp"

#include "KitchenHandling.hpp"

#include <unistd.h>

class tmpTask : public ITask
{
public:
  tmpTask() {};
  virtual ~tmpTask() {};

  void execute()
  {
    std::cout << "Hello i'm a cooker !" << std::endl;
  }
};

KitchenHandling::KitchenHandling(NamedPipe &in, NamedPipe &out)
  : _in(in), _out(out)
{

}

KitchenHandling::~KitchenHandling()
{

}

void KitchenHandling::execute()
{
  ThreadPool<PThread> cookers(10);

  std::cout << "Hello I'm a kitchen and I'm magic !!" << std::endl;
  cookers.queueTask(new tmpTask);
  cookers.queueTask(new tmpTask);
  cookers.queueTask(new tmpTask);
  usleep(46870);
}
