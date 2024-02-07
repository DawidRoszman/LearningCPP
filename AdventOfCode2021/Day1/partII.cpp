#include <fstream>
#include <iostream>
#include <vector>

int main() {
  int couter{0};
  std::vector<int> numbers;
  std::fstream file;
  std::string line;
  long prevWindow{0};

  file.open("input.txt", std::ios::in);
  if (!file.is_open()) {
    std::cerr << "Error: file not opened" << std::endl;
    return 1;
  }
  while (std::getline(file, line)) {
    numbers.push_back(std::stoi(line));
  }

  file.close();

  for (int i = 1; i < numbers.size() - 1; i++) {
    if (prevWindow == 0) {
      prevWindow = numbers[i - 1] + numbers[i] + numbers[i + 1];
      continue;
    }
    long currWindow = numbers[i - 1] + numbers[i] + numbers[i + 1];
    if (currWindow > prevWindow) {
      couter++;
    }
    prevWindow = currWindow;
  }
  std::cout << couter << std::endl;

  return 0;
}
