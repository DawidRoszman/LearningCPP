#include <fstream>
#include <iostream>
#include <string>

int main() {
  std::fstream file;
  std::string line;
  int prevLine{-1};
  int couter{0};
  file.open("input.txt", std::ios::in);

  if (!file.is_open()) {
    std::cerr << "Error: file not opened" << std::endl;
    return 1;
  }

  while (std::getline(file, line)) {
    int currLine = std::stoi(line);
    if (prevLine != -1) {
      if (currLine > prevLine) {
        couter++;
      }
    }
    prevLine = currLine;
  };

  file.close();

  std::cout << couter << std::endl;

  return 0;
}
