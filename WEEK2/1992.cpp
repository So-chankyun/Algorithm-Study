#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N = 0;
string s;
char map[101][101] = {};

string recursive(int y,int x,int size)
{
  // 만약 n == 1 이면 탈출
  if(size == 1)
    return string(1, map[y][x]);
  
  char b = map[y][x];

  string ret = "";

  for(int i = y;i < y + size;i++)
  {
    for(int j = x;j < x + size;j++)
    {
      if(b != map[i][j])
      {
        ret += '(';
        ret += recursive(y,x,size/2);
        ret += recursive(y, x + size/2, size/2);
        ret += recursive(y + size/2, x, size/2);
        ret += recursive(y + size/2,x+size/2,size/2);
        ret += ')';
        return ret;
      }
    }
  }

  return string(1,map[y][x]);
}

int main()
{
  ios_base::sync_with_stdio(0);

  cin >> N;

  for(int i =0;i<N;i++)
  {
    cin >> s;
    for(int j =0;j<N;j++)
    {
      map[i][j] = s[j];
    }
  }
  
  cout << recursive(0,0,N) << '\n';

  return 0;
}