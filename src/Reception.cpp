#include <sstream>
#include <algorithm>
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

#include "Reception.hpp"
#include "PThread.hpp"
#include "PizzaFactory.hpp"

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
  _typesPizza["regina"] = APizza::Regina;
  _typesPizza["margarita"] = APizza::Margarita;
  _typesPizza["americaine"] = APizza::Americaine;
  _typesPizza["fantasia"] = APizza::Fantasia;
  _sizesPizza["S"] = APizza::S;
  _sizesPizza["M"] = APizza::M;
  _sizesPizza["L"] = APizza::L;
  _sizesPizza["XL"] = APizza::XL;
  _sizesPizza["XXL"] = APizza::XXL;
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
    {
      std::string	str;

      str = lex.substr(1, lex.size() - 1);
      std::string::const_iterator it = str.begin();
      while (it != str.end() && std::isdigit(*it)) ++it;
      if (it == str.end() && !str.empty())
        return true;
    }
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

void Reception::parseLexem(const std::vector<std::string>& tokens)
{
  int	i;

  i = 0;
  for (std::list<Reception::Lexem>::iterator it = _lex.begin(),
       end = _lex.end(); it != end; ++it)
    {
      if (i == (COMMA + 1))
        i = 0;
      if (!(i == *it))
        {
          std::cerr << "Your command is invalid" << std::endl;
          return ;
        }
      ++i;
    }
  if (i == COMMA + 1)
    {
      std::cerr << "Your command is invalid" << std::endl;
      return ;
    }
  fillPizzaList(tokens);
}

void Reception::fillPizzaList(const std::vector<std::string>& tokens)
{
  std::list<APizza *> pizzas;
  APizza::TypePizza type;
  APizza::TaillePizza size;
  int nb = 0;

  for (size_t tok = 0; tok <= (tokens.size() - 1); tok += 4)
    {
      type = _typesPizza[tokens[tok]];
      size = _sizesPizza[tokens[tok + 1]];
      nb = atoi((tokens[tok + 2].substr(1, tokens[tok + 2].size() - 1)).c_str());
      for (; nb > 0; --nb)
        {
          pizzas.push_back(PizzaFactory::newPizza(type, size));
        }
    }
  _commands.push_back(new Command(pizzas));
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
	    {
	      std::cerr << "Your command is invalid" << std::endl;
	      break;
	    }
      	}

      parseLexem(tokens);
      _lex.clear();
      for (std::deque<Kitchen*>::iterator it = _kitchens.begin(), end = _kitchens.end();
           it != end; ++it)
        {
          (*it)->getStatus();
        }

      std::cout << "La Piazza> ";
    }
}
