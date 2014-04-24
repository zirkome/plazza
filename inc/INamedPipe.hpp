#ifndef INAMEDPIPE_HPP_
# define INAMEDPIPE_HPP_

class			INamedPipe
{
public:
  virtual int		write(const std::string &str) = 0;
  virtual std::string	read() = 0;
  virtual int		open(int mode) = 0;
  virtual int		close(int mode) = 0;
  // overload operator <<
  // overload operator >>
  virtual ~INamedPipe() {};
};


#endif /* !INAMEDPIPE_HPP_ */
