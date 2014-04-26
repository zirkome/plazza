#include "Graphique.hpp"

Graphique::Graphique(Reception& pizza)
  : _time(20.0), _pizza(pizza)
{
}

Graphique::~Graphique()
{
}

void Graphique::createWindows(const Point2d<int>& size)
{
  std::string	error;

  if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
      error = "Can't Init SDL: ";
      error += SDL_GetError();
      throw std::runtime_error(error);
    }
  if (((_win = SDL_CreateWindow("Plazza", 0, 0,
                                size.x(), size.y(), SDL_WINDOW_SHOWN)) == NULL)
      || ((_rend = SDL_CreateRenderer(_win, -1, SDL_RENDERER_ACCELERATED)) == NULL))
    {
      error = "SDL can't create window: ";
      error += SDL_GetError();
      throw std::runtime_error(error);
    }
  SDL_RenderClear(_rend);
  SDL_RenderPresent(_rend);
}

void Graphique::drawSquare(const Box<int>& square, blockType type)
{
  SDL_Rect	pos;
  std::vector<unsigned char>& colors = _colorMap.at(type);

  pos.x = square.getPos().x();
  pos.y = square.getPos().y();
  pos.w = square.getSize().w();
  pos.h = square.getSize().h();
  SDL_SetRenderDrawColor(_rend, colors[0], colors[1], colors[2], 0x00);
  SDL_RenderDrawRect(_rend, &pos);
}

void Graphique::clearScreen()
{
  SDL_SetRenderDrawColor(_rend, 0x00, 0x00, 0x00, 0x00);
  SDL_RenderClear(_rend);
}

void Graphique::drawScreen()
{
  SDL_RenderPresent(_rend);
}

void Graphique::update()
{
  SDL_Event	event;
  bool		quit = false;

  while (!quit)
    {
      _time.startFrame();
      while (SDL_PollEvent(&event))
        {
          if (event.window.event == SDL_WINDOWEVENT_CLOSE)
            quit = true;
          else if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP)
            {

            }
        }
      clearScreen();
      drawScreen();
      _time.endFrame();
      _time.alignOnFps();
    }
}

void Graphique::execute()
{
  createWindows(Point2d<int>(1024, 972));
  update();
  SDL_Quit();
}
