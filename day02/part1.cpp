#include <iostream>
#include <fstream>
#include <sstream>

bool isLineValid(std::string line);

bool isAbsDistOK(int lastNum, int num)
{
  int val = abs(lastNum-num);
  return val >= 1 && val <= 3;
}

bool isPairValid(int lastNum, int num, bool isAsc)
{
  if (!isAbsDistOK(lastNum, num)) {
    return false;
  }
  return isAsc ? lastNum < num : lastNum > num;
}



bool isLineValid(std::string line)
{
  std::string token, lastToken;
  std::istringstream tokenStream(line);
  std::getline(tokenStream, lastToken, ' ');
  std::getline(tokenStream, token, ' ');
  int lastNum = std::stoi(lastToken), num = std::stoi(token);
  bool isAsc = lastNum < num; // used to know if the line should be ascending of descending
  if (!isPairValid(lastNum, num, isAsc)) {
    return false;
  }
  while (std::getline(tokenStream, token, ' '))
  {
    lastNum = num;
    num = std::stoi(token);
    if (!isPairValid(lastNum, num, isAsc))
    {
      return false;
    }
  }
  return true;
}

int main()
{
  std::ifstream file("input.txt");
  int count = 0;
  if (!file.is_open())
  {
    std::cerr << "file not open";
    return 1;
  }
  std::string line;

  while (std::getline(file, line))
  {
    count = isLineValid(line) ? count + 1 : count;
  }

  std::cout << "count : " << count;
  return 0;
}