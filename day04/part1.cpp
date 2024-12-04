#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
const string XMAS = "XMAS";

bool checkWord(int h, int w, int x, int y, const vector<string> &lines)
{
  int height = lines.size();
  int width = lines[0].size();
  for (int i = 0; i < 4; i++)
  {
    int newH = h + y * i;
    int newW = w + x * i;
    if (newH < 0 || newW < 0 || newH >= height || newW >= width || lines[newH][newW] != XMAS[i])
    {
      return false;
    }
  }
  return true;
}

int checkString(int h, int w, const vector<string> &lines)
{
  int count = 0;

  int height = lines.size(), width = lines[0].size(); // assuming that the input are in square shap
  vector<pair<int, int>> directions = {
      {0, 1},   // Right
      {1, 0},   // Down
      {1, 1},   // Diagonal-right-down
      {1, -1},  // Diagonal-left-down
      {0, -1},  // Left
      {-1, 0},  // Up
      {-1, -1}, // Diagonal-left-up
      {-1, 1}   // Diagonal-right-up
  };
  for (auto &&[x, y] : directions)
  {
    checkWord(h, w, x, y, lines) && count++;
  }
  return count;
}

int main()
{
  ifstream file("input.txt");
  if (!file.is_open())
  {
    cerr << "file not open";
    return 1;
  }
  vector<string> lines;
  string lineFile;
  while (getline(file, lineFile))
  {
    lines.push_back(lineFile);
  }
  file.close();

  int count = 0;
  int linesSize = lines.size();
  for (int i = 0; i < linesSize; i++)
  {
    string line = lines[i];
    int lineSize = line.size();
    for (int j = 0; j < lineSize; j++)
    {
      count += checkString(i, j, lines);
    }
  }
  cout << count << endl;
  return 0;
}