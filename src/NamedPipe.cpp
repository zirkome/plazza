#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include "../inc/NamedPipe.hpp"

NamedPipe::NamedPipe(const std::string &path)
{
  _path = path;
  if (mkfifo(_path.c_str(), 0644) == -1)
    {
      std::cerr << "error: NamedPipe: mkfifo failed" << std::endl;
      return ;
    }
}

NamedPipe::~NamedPipe()
{
}

int		NamedPipe::open(int mode)
{
  if (mode == 1)
    {
      _ifs.open(_path.c_str(),
	   std::ifstream::in);
      if (_ifs.fail() == true)
	{
	  std::cerr << "error: NamedPipe: _fs.open() failed" << std::endl;
	  return (-1);
	}
    }
  else if (mode == 2)
    {
      _ofs.open(_path.c_str(),
	   std::ofstream::out);
      if (_ofs.fail() == true)
	{
	  std::cerr << "error: NamedPipe: _fs.open() failed" << std::endl;
	  return (-1);
	}
    }
  else
    return (-1);
  return (0);
}

int		NamedPipe::close(int mode)
{
  if (mode == 1)
    {
      _ifs.close();
      if (_ifs.fail() == true)
	{
	  std::cerr << "error: ~NamedPipe: _ifs.close() failed" << std::endl;
	  return (-1);
	}
    }
  else if (mode == 2)
    {
      _ofs.close();
      if (_ofs.fail() == true)
	{
	  std::cerr << "error: ~NamedPipe: _ofs.close() failed" << std::endl;
	  return (-1);
	}
    }
  else
    return (-1);
  return (0);
}

int		NamedPipe::write(const std::string &str)
{
  if (this->open(2) == -1)
    {
      std::cerr << "error: write: NamedPipe.open() failed" << std::endl;
      return (-1);
    }
  _ofs << str;
  if (_ofs.fail() == true)
    {
      std::cerr << "error: _ofs.write() failed" << std::endl;
      return (-1);
    }
  if (this->close(2) == -1)
    {
      std::cerr << "error: write: NamedPipe.close() failed" << std::endl;
      return (-1);
    }
  return (0);
}

std::string		NamedPipe::read()
{
  std::string		read;
  std::stringstream	ss;

  if (this->open(1) == -1)
    {
      std::cerr << "error: read: NamedPipe.open() failed" << std::endl;
      return (NULL);
    }
  ss << _ifs.rdbuf();
  read = ss.str();
  if (this->close(1) == -1)
    {
      std::cerr << "error: NamedPipe.close() failed" << std::endl;
      return (NULL);
    }
  return (read);
}
