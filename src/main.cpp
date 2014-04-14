#include <iostream>

int		main(int argc, char *argv[])
{
  if (argc != 4)
    {
      std::cerr << "Invalid number of arguments" << std::endl;
      return (1);
    }
  for (int i = 0; i < argc; i++)
    std::cout << argv[i] << std::endl;
  return (0);
}
