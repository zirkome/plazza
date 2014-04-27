#include <sys/types.h>
#include <sys/stat.h>
#include <stdexcept>
#include <cerrno>
#include <cstring>
#include <unistd.h>
#include <sstream>

#include "../inc/InNamedPipe.hpp"

InNamedPipe::InNamedPipe(const std::string &path)
{
  struct stat	buf;

  _path = path;
  if (stat(_path.c_str(), &buf) == -1)
    {
      if (mkfifo(_path.c_str(), 0644) == -1)
	throw std::runtime_error(std::string("NamedPipe") + strerror(errno));
    }
  _fs.open(_path.c_str());
  if (_fs.fail() == true)
    throw std::runtime_error(std::string("NamedPipe") + strerror(errno));
}

InNamedPipe::~InNamedPipe()
{
  struct stat	buf;

  _fs.close();
  if (_fs.fail() == true)
    throw std::runtime_error(std::string("~NamedPipe") + strerror(errno));
  if (stat(_path.c_str(), &buf) == 0)
    {
      if (unlink(_path.c_str()))
	throw std::runtime_error(std::string("~NamedPipe") + strerror(errno));
    }
}

std::string             InNamedPipe::read()
{
  std::string           read;
  std::stringstream     ss;

  ss << _fs.rdbuf();
  read = ss.str();
  return (read);
}
