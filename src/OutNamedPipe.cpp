#include <sys/types.h>
#include <sys/stat.h>
#include <stdexcept>
#include <cerrno>
#include <cstring>
#include <unistd.h>
#include <sstream>
#include <iostream>

#include "../inc/OutNamedPipe.hpp"

OutNamedPipe::OutNamedPipe(const std::string &path)
{
  struct stat	buf;

  _path = path;
  if (stat(_path.c_str(), &buf) == -1)
    {
      if (mkfifo(_path.c_str(), 0644) == -1)
	throw std::runtime_error(std::string("NamedPipe: ") + strerror(errno));
    }
  _fs.open(_path.c_str());
  if (_fs.fail() == true)
    throw std::runtime_error(std::string("NamedPipe: ") + strerror(errno));
}

OutNamedPipe::~OutNamedPipe()
{
  struct stat	buf;

  _fs.close();
  if (_fs.fail() == true)
    throw std::runtime_error(std::string("~NamedPipe: ") + strerror(errno));
  if (stat(_path.c_str(), &buf) == 0)
    {
      if (unlink(_path.c_str()))
	throw std::runtime_error(std::string("~NamedPipe: ") + strerror(errno));
    }
}

int             OutNamedPipe::write(const std::string &str)
{
  _fs << str;
  if (_fs.fail() == true)
    {
      std::cerr << "error: write() failed" << std::endl;
      return (-1);
    }
  return (0);
}
