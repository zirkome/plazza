#ifndef COOKER_H
# define COOKER_H

# include "ITask.hpp"

class Cook : public ITask
{
public:
  Cook();
  virtual ~Cook();

  virtual void execute();

private:


};

#endif // COOKER_H
