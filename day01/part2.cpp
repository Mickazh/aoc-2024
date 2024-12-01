#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

int main()
{
  std::ifstream file("input.txt");
  if (!file.is_open())
  {
    std::cerr << "file not open";
    return 1;
  }

  std::string line;
  std::vector<int> leftNumbers;
  std::unordered_map<int, int> map;

  while (std::getline(file, line))
  {
    std::string valueLeft = "", valueRight = "";

    std::string::iterator begin = line.begin();
    std::string::iterator end = line.end();
    end--;

    while (std::isdigit(*begin))
    {
      valueLeft += *begin;
      begin++;
    }

    while (std::isdigit(*end))
    {
      valueRight = *end + valueRight;
      end--;
    }

    leftNumbers.push_back(std::stoi(valueLeft));
    map[std::stoi(valueRight)]++;
  }

  int res = 0;

  for (int num : leftNumbers)
  {
    res += num * map[num];
  }

  std::cout << res << std::endl;

  return 0;
}