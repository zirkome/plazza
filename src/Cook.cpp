#include <iostream>

#include "Cook.hpp"

Cook::Cook(APizza& pizza)
  : _pizza(pizza)
{
}

Cook::~Cook()
{
}

void Cook::execute()
{
  std::cout << "Hello I'm a cooking this delicious pizza !" << std::endl;
}
