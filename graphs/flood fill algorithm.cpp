#include <bits/stdc++.h>
using namespace std;
 
// Function to check valid coordinate
int validCoord(int x, int y, int n, int m)
{
    if (x < 0 || y < 0)
        return 0;
    if (x >= n || y >= m)
        return 0;
    return 1;
}
 
// Function to run bfs
void bfs(int n, int m, int data[][8],int x, int y, int color)
{
   
  // Visiing array
  int vis[101][101];
  memset(vis, 0, sizeof(vis));
   
  // Creating queue for bfs
  queue<pair<int, int> > q;
  q.push({ x, y });
   
  // Marking {x, y} as visited
  vis[x][y] = 1;
   
  // Until queue is emppty
  while (!q.empty())
  {
    pair<int, int> coord = q.front();
    int x = coord.first;
    int y = coord.second;
    int preColor = data[x][y];
 
    data[x][y] = color; 

    q.pop();
 
    if (validCoord(x + 1, y, n, m)
        && vis[x + 1][y] == 0
        && data[x + 1][y] == preColor)
    {
      q.push({ x + 1, y });
      vis[x + 1][y] = 1;
    }
     
    if (validCoord(x - 1, y, n, m)
        && vis[x - 1][y] == 0
        && data[x - 1][y] == preColor)
    {
      q.push({ x - 1, y });
      vis[x - 1][y] = 1;
    }
     
    if (validCoord(x, y + 1, n, m)
        && vis[x][y + 1] == 0
        && data[x][y + 1] == preColor)
    {
      q.push({ x, y + 1 });
      vis[x][y + 1] = 1;
    }
     
    if (validCoord(x, y - 1, n, m)
        && vis[x][y - 1] == 0
        && data[x][y - 1] == preColor)
    {
      q.push({ x, y - 1 });
      vis[x][y - 1] = 1;
    }
  }
   
  // Printing The Changed Matrix Of Pixels
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout << data[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}
 
int main()
{
  int n, m, x, y, color;
  n = 8;
  m = 8;
 
  int data[8][8] = {
    { 1, 1, 1, 1, 1, 1, 1, 1 },
    { 1, 1, 1, 1, 1, 1, 0, 0 },
    { 1, 0, 0, 1, 1, 0, 1, 1 },
    { 1, 2, 2, 2, 2, 0, 1, 0 },
    { 1, 1, 1, 2, 2, 0, 1, 0 },
    { 1, 1, 1, 2, 2, 2, 2, 0 },
    { 1, 1, 1, 1, 1, 2, 1, 1 },
    { 1, 1, 1, 1, 1, 2, 2, 1 },
  };
 
  x = 4, y = 4, color = 3;
   
  // Function Call
  bfs(n, m, data, x, y, color);
  return 0;
}