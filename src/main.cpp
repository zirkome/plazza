#include <iostream>
#include <exception>
#include <stdexcept>
#include <sstream>
#include <unistd.h>

#include "Reception.hpp"

int main(int argc, char *argv[])
{
  try
    {
      TimeHandler time(1.0 / 5.0);
      std::stringstream ss;
      float multiplier;
      size_t cookPerKitchen;
      float stockRenewalTime;

      if (argc != 4)
        {
          std::cerr << "Usage: " << argv[0]
		    << " multiplier cooker_per_kitchen stockRenewalTime"
		    << std::endl;
          return (1);
        }
      ss.str(argv[1]);
      if (!(ss >> multiplier))
        throw std::runtime_error("Wrong argument type");
      ss.clear();
      ss.str(argv[2]);
      if (!(ss >> cookPerKitchen))
        throw std::runtime_error("Wrong argument type");
      ss.clear();
      ss.str(argv[3]);
      if (!(ss >> stockRenewalTime))
        throw std::runtime_error("Wrong argument type");

      Reception boboPizza(multiplier, cookPerKitchen, stockRenewalTime);

      boboPizza.run();
    }
  catch (const std::exception& e)
    {
      std::cerr << e.what() << std::endl;
    }
  return (0);
}
