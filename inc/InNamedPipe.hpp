#ifndef INNAMEDPIPE_HPP_
# define INNAMEDPIPE_HPP_

# include <string>
# include <fstream>

class		InNamedPipe
{
private:
  std::string	_path;
  std::ifstream	_fs;

public:
  InNamedPipe(const std::string &path);
  virtual ~InNamedPipe();

  std::string read();

  std::ifstream& getStream() {return _fs;};
};

#endif /* !INNAMEDPIPE_HPP_ */
