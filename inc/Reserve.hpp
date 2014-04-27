#ifndef _RESERVE_H_
# define _RESERVE_H_

# include <map>
# include <iostream>

# include "APizza.hpp"
# include "PMutex.hpp"
# include "ScopeLock.hpp"

class Reserve
{
public:
  Reserve();
  virtual ~Reserve();

public:
  void consume(APizza::Ingredients ingr);
  void regenerate();

private:
  std::map<APizza::Ingredients, size_t> _ingredients;
  IMutex* _mutex;
};

#endif /* _RESERVE_H_ */
