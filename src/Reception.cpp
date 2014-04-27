#include <sstream>
#include <algorithm>
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

#include "Reception.hpp"
#include "PThread.hpp"

Reception::Reception(float cookMultiplier, size_t cookPerKitchen, float stockRenewalTime)
  : _time(1.0 / (stockRenewalTime / 1000.0)), _cookMultiplier(cookMultiplier),
    _cookPerKitchen(cookPerKitchen), _stockRenewalTime(stockRenewalTime), _KitchenCounter(0)
{
  std::stringstream tmp;

  _lexems["regina"] = Reception::TYPE;
  _lexems["fantasia"] = Reception::TYPE;
  _lexems["margarita"] = Reception::TYPE;
  _lexems["americana"] = Reception::TYPE;
  _lexems["S"] = Reception::SIZE;
  _lexems["M"] = Reception::SIZE;
  _lexems["L"] = Reception::SIZE;
  _lexems["XL"] = Reception::SIZE;
  _lexems["XXL"] = Reception::SIZE;
  _lexems[";"] = Reception::COMMA;

  _sdl = new PThread();
  _sdl->setTask(new Graphique(*this));
  tmp << _KitchenCounter;
  _kitchens.push_back(new Kitchen(tmp.str(), _cookMultiplier));
  ++_KitchenCounter;
}

Reception::~Reception()
{
  delete _sdl;
  for (std::deque<Kitchen*>::iterator it = _kitchens.begin(), end = _kitchens.end();
       it != end; ++it)
    {
      delete *it;
    }
}

void replaceAll(std::string& str, const std::string& from, const std::string& to)
{
  if (from.empty())
    return;

  size_t start_pos = 0;

  while ((start_pos = str.find(from, start_pos)) != std::string::npos)
    {
      str.replace(start_pos, from.length(), to);
      start_pos += to.length();
    }
}

bool Reception::isNumber(const std::string& lex) const
{
  if (lex.at(0) == 'x')
    return true;
  return false;
}

Reception::Lexem Reception::findType(const std::string& lex) const
{
  std::map<std::string, Reception::Lexem>::const_iterator it
    = _lexems.find(lex);

  if (it != _lexems.end())
    return it->second;
  else if (isNumber(lex))
    return NUMBER;
  return UNKNOWN;
}

void Reception::lexLine(const std::vector<std::string>& tokens)
{
  for (std::vector<std::string>::const_iterator it = tokens.begin(), end = tokens.end();
       it != end; ++it)
    {
      _lex.push_back(findType(*it));
    }
}

void Reception::parseLexem()
{
  int	i;
  std::list<APizza *> pizzas;
  
  i = 0;
  for (std::list<Reception::Lexem>::iterator it = _lex.begin(), end = _lex.end();
       it != end; ++it)
    {
      if (i == (COMMA + 1))
	i = 0;
      if (!(i == *it))
	std::cout << "ERROR: not ok" << std::endl;
      ++i;
    }
  if (i == COMMA + 1)
    std::cout << "ERROR: not ok" << std::endl;
}

void Reception::run()
{
  std::string line;

  std::cout << "La Piazza> ";
  while(std::getline(std::cin, line))
    {
      replaceAll(line, ";", " ; ");
      std::istringstream iss(line);
      std::vector<std::string> tokens;

      std::copy(std::istream_iterator<std::string>(iss),
		std::istream_iterator<std::string>(),
		std::back_inserter< std::vector<std::string> >(tokens));

      lexLine(tokens);

      for (std::list<Reception::Lexem>::iterator it = _lex.begin(), end = _lex.end();
      	   it != end; ++it)
      	{
	  if (*it == UNKNOWN)
	    std::cerr << "Your command is invalid" << std::endl;
      	}

      parseLexem();
      _lex.clear();
      std::cout << "La Piazza> ";
    }
}
