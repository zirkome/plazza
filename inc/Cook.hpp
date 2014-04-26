#ifndef COOKER_H
# define COOKER_H

# include "ITask.hpp"
# include "APizza.hpp"

class Cook : public ITask
{
public:
  Cook(APizza& pizza);
  virtual ~Cook();

  virtual void execute();

private:
  APizza& _pizza;
};

#endif // COOKER_H
