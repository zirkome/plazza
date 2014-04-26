#ifndef NAMEDPIPE_HPP_
# define NAMEDPIPE_HPP_

# include <fstream> 
# include "INamedPipe.hpp"

class		NamedPipe : public INamedPipe
{
public:
  NamedPipe(const std::string &path);
  virtual ~NamedPipe();
  
  int		write(const std::string &str);
  std::string	read();
  int		open(int mode);
  int		close(int mode);

private:
  std::string	_path;
  std::ifstream	_ifs;
  std::ofstream	_ofs;
};

#endif /* !NAMEDPIPE_HPP_ */
