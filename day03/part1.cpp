#include <iostream>
#include <fstream>
#include <regex>

int main()
{
  std::ifstream file("input.txt");
  if (!file.is_open())
  {
    std::cerr << "file not open";
    return 1;
  }
  std::string line;
  std::regex r(R"(mul\((\d{1,3}),(\d{1,3})\))");
  int count = 0;
  while (std::getline(file, line))
  {
    for (std::smatch sm; regex_search(line, sm, r);)
    {
      count += std::stoi(sm[1]) * std::stoi(sm[2]);
      line = sm.suffix();
    }
  }

  std::cout << count << std::endl;
  return 0;
}