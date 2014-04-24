#ifndef IPROCESS_HPP_INCLUDED
#define IPROCESS_HPP_INCLUDED

#include "IThread.hpp"

class IProcess : public IThread
{
public:

  virtual ~IProcess() {};
};

#endif // IPROCESS_HPP_INCLUDED
