#include <fstream>
#include <iostream>

void move(long &distance, long &depth, long &aim, std::string &operation,
          int &number) {

  if (operation == "down") {
    aim += number;
  } else if (operation == "up")
    aim -= number;
  else if (operation == "forward") {
    distance += number;
    depth += aim * number;
  } else
    std::cout << "Invalid operation";
}

int main() {
  std::fstream file;
  std::string line;
  long depth{0}, distance{0}, aim{0};

  file.open("input.txt", std::ios::in);
  if (!file.is_open())
    return 1;

  while (std::getline(file, line)) {
    std::string operation;
    int number;
    operation = line.substr(0, line.find(" "));
    number = std::stoi(line.substr(line.find(" ") + 1, line.size()));

    move(distance, depth, aim, operation, number);
  }

  std::cout << "Distance: " << distance << " Depth: " << depth << std::endl;
  std::cout << "Total: " << distance * depth << std::endl;
  return 0;
}
