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
  std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
  std::regex r(R"(mul\((\d{1,3}),(\d{1,3})\)|don't\(\)|do\(\))");
  int count = 0;
  bool shouldDo = true;
  for (std::smatch sm; std::regex_search(content, sm, r);)
  {
    if (sm[0].compare("don't()") == 0)
    {
      shouldDo = false;
    }
    else if (sm[0].compare("do()") == 0)
    {
      shouldDo = true;
    }
    else if (shouldDo)
    {
      count += std::stoi(sm[1]) * std::stoi(sm[2]);
    }

    content = sm.suffix();
  }
  std::cout << count << std::endl;
  return 0;
}