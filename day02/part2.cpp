#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

bool isLineValid(std::string line);

bool isAbsDistOK(int lastNum, int num)
{
  int val = abs(lastNum - num);
  return val >= 1 && val <= 3;
}

bool isPairValid(int lastNum, int num, bool isAsc)
{
  if (!isAbsDistOK(lastNum, num))
  {
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
  if (!isPairValid(lastNum, num, isAsc))
  {
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

bool isLineValid(std::vector<int> line)
{
  int lastNum = line[0], num = line[1];
  bool isAsc = lastNum < num;
  if (!isPairValid(lastNum, num, isAsc))
  {
    return false;
  }
  for (int i = 2; i < line.size(); i++)
  {
    lastNum = num;
    num = line[i];
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
    std::istringstream tokenStream(line);
    std::vector<int> numbers;
    std::string token;
    while (tokenStream >> token)
    {
      numbers.push_back(std::stoi(token));
    }

    if (isLineValid(line))
    {
      count++;
      continue;
    }
    
    int vSize = numbers.size();
    std::vector<int> numbersCopy;
    for (int i = 0; i < vSize; i++)
    {
      numbersCopy = numbers;
      numbersCopy.erase(std::next(numbersCopy.begin(), i));
      if (isLineValid(numbersCopy)) {
        count++;
        break;
      }     
    }
  }

  std::cout << "count : " << count;
  return 0;
}