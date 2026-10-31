#include <iostream>

int main(int argc, char **argv)
{

  // References   
  int a = 10;
  int b = a;
  const int& c = a;

  std::cout << "a = " << a << ", b = " << b << ", c = " << c << "\n";

  a = 11;

  std::cout << "a = " << a << ", b = " << b << ", c = " << c << "\n";

  a = 21;

  std::cout << "a = " << a << ", b = " << b << ", c = " << c << "\n";

  return 0;
}
