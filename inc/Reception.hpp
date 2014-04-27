#ifndef RECEPTION_HPP_INCLUDED
# define RECEPTION_HPP_INCLUDED

# include <deque>
# include <iterator>
# include <list>

class Reception;

# include "Command.hpp"
# include "Graphique.hpp"

# include "Kitchen.hpp"
# include "TimeHandling.hpp"
# include "APizza.hpp"

class Reception
{
private:
  enum Lexem
    {
      TYPE,
      SIZE,
      NUMBER,
      COMMA,
      UNKNOWN
    };

public:
  Reception(float cookMultiplier, size_t cookPerKitchen, float stockRenewalTime);
  ~Reception();

  void run();

private:
  bool isNumber(const std::string& lex) const;
  Lexem findType(const std::string& lex) const;
  void lexLine(const std::vector<std::string>& tokens);
  void parseLexem(const std::vector<std::string>& tokens);
  void fillPizzaList(const std::vector<std::string>& tokens);

private:
  TimeHandler _time;

  float _cookMultiplier;
  size_t _cookPerKitchen;
  float _stockRenewalTime;

  int _KitchenCounter;
  IThread *_sdl;
  std::deque<Kitchen*> _kitchens;
  std::deque<Command*> _commands;
  std::list<Lexem> _lex;
  std::map<std::string, Lexem> _lexems;
  std::map<std::string, APizza::TypePizza> _typesPizza;
  std::map<std::string, APizza::TaillePizza> _sizesPizza;
};

#endif // RECEPTION_HPP_INCLUDED
