#ifndef OUTNAMEDPIPE_HPP_
# define OUTNAMEDPIPE_HPP_

# include <string>
# include <fstream>

class		OutNamedPipe
{
private:
  std::string	_path;
  std::ofstream	_fs;

public:
  OutNamedPipe(const std::string &path);
  virtual ~OutNamedPipe();

  int           write(const std::string &str);
};

#endif /* !OUTNAMEDPIPE_HPP_ */
