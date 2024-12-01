#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>

int main()
{
  std::ifstream file("input.txt");
  if (!file.is_open())
  {
    std::cerr << "file not open";
    return 1;
  }

  std::string line;
  std::priority_queue<int> pqLeft, pqRight;

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
    
    pqLeft.push(std::stoi(valueLeft));
    pqRight.push(std::stoi(valueRight));
  }

  int res = 0;
  int size = pqLeft.size();
  for (int i = size - 1; i >= 0; i--)
  {
    res += abs(pqLeft.top() - pqRight.top());
    pqLeft.pop();
    pqRight.pop();
  }
  
  std::cout << res << std::endl;

  return 0;
}