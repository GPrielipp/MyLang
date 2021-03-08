#include "Lexer.hpp"
#include <iostream>
#include <string>
#include <signal.h>

void program_CTRL_C(int signum)
{
  std::cout << "\nClosing MyLang shell ...\n";
  exit(signum);
}

int main(void)
{
  // exit the program cleanly on ctrl+c
  signal(SIGINT, &program_CTRL_C);

  while (true)
  {
    std::string input;
    std::cout << "MyLang > ";
    std::cin >> input;
    std::cout << input << "\n";
  }
  return 0;
}