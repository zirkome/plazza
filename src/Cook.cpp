#include <iostream>

#include <fstream>

#include "Cook.hpp"

static std::ofstream log("pizza.log");

Cook::Cook(APizza& pizza)
  : _pizza(pizza)
{
}

Cook::~Cook()
{
}

void Cook::execute()
{
  log << "Hello I'm a cooking this delicious pizza !" << std::endl;
}
