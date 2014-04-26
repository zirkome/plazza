#ifndef _ITASK_H_
# define _ITASK_H_

class ITask
{
public:
  virtual ~ITask() {}

public:
  virtual void execute() = 0;
};

#endif /* _ITASK_H_ */
