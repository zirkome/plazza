#ifndef GRAPHIQUE_HPP_
#define GRAPHIQUE_HPP_

# include <SDL2/SDL.h>
# include <iostream>
# include <map>
# include <vector>
# include <exception>
# include <stdexcept>

# include "Reception.hpp"

# include "TimeHandling.hpp"
# include "Point2d.hpp"
# include "Box.hpp"

# include "ITask.hpp"

class Graphique : public ITask
{
public:
  enum blockType
  {
    RECEPTION,
    KITCHEN,
    COOKER,
    INGREDIENT
  };

  Graphique(Reception& pizza);
  ~Graphique();

  void	createWindows(const Point2d<int>& size);
  void	drawSquare(const Box<int>& square, blockType type);
  void	update();
  void	clearScreen();
  void	drawScreen();

  virtual void execute();

private:
  TimeHandler _time;
  Reception& _pizza;
  std::map<blockType, std::vector<unsigned char> > _colorMap;
  SDL_Window	*_win;
  SDL_Renderer	*_rend;
};

#endif
