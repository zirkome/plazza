#include "APizza.hpp"

APizza::APizza(TypePizza type, TaillePizza size)
  : _type(type), _size(size), _done(false)
{
}

APizza::TaillePizza APizza::getSize() const
{
  return _size;
}

APizza::TypePizza APizza::getType() const
{
  return _type;
}

bool APizza::isDone() const
{
  return _done;
}

void APizza::setDone(bool done)
{
  _done = done;
}
