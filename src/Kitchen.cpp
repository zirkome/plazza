#include <algorithm>
#include <sstream>
#include <iostream>
#include <string>
#include <iterator>

#include "ProcUnix.hpp"
#include "InNamedPipe.hpp"
#include "OutNamedPipe.hpp"

#include "Kitchen.hpp"

Kitchen::Kitchen(const std::string& name, size_t nbCookers)
  : _process(NULL)
{
  std::string inName = std::string("/tmp/kitin") + name;
  std::string outName = std::string("/tmp/kitout") + name;

  KitchenHandling *tmp = new KitchenHandling(outName, inName, nbCookers);
  _process = new ProcUnix(*tmp);
  _in = new InNamedPipe(inName);
  _out = new OutNamedPipe(outName);
  delete tmp;
}

Kitchen::~Kitchen()
{
  delete _in;
  delete _out;
  delete _process;
}

void Kitchen::newOrder(APizza* pizza)
{
  _out->getStream() << PizzaFactory::packPizza(*pizza) << std::endl;
}

std::vector<IThread::State> Kitchen::getStatus() const
{
  _out->getStream() << "STATUS" << std::endl;
  std::string status;
  std::string state;
  std::vector<IThread::State> res;
  std::getline(_in->getStream(), status);

  std::istringstream iss(status);
  std::vector<std::string> tokens;
  std::copy(std::istream_iterator<std::string>(iss),
            std::istream_iterator<std::string>(),
            std::back_inserter< std::vector<std::string> >(tokens));

  for (std::vector<std::string>::const_iterator it = tokens.begin(), end = tokens.end();
       it != end; ++it)
    {
      if ((*it) == "THR_ALIVE")
        res.push_back(IThread::THR_ALIVE);
      else if ((*it) == "THR_DEAD")
        res.push_back(IThread::THR_DEAD);
      else if ((*it) == "THR_WAITING")
        res.push_back(IThread::THR_WAITING);
    }
  return res;
}
