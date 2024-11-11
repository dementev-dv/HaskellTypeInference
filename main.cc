#include "lexer.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

std::string readf(const char* path) {
  std::ifstream f(path);
  std::stringstream ss;
  ss << f.rdbuf();
  f.close();
  return ss.str();
}

int main(int argc, char** argv) {

  if (argc != 2) {
    std::cout << "Usage: " << argv[0] << " path/to/file.ram" << std::endl;
    exit(1);
  }

  std::string program = readf(argv[1]);

  Lexer lexer(program);
  Token curr(START, "");
  std::cout << program << std::endl;

  while (curr.tag() != END) {
    curr = lexer.Next();
    std::cout << curr.str() << std::endl;
  }

  return 0;
}
