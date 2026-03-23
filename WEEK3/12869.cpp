#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int visited[61][61][61];
int a[3];
struct position{
  int a,b,c;
};
queue<position> pos;
int N;

// 공격의 종류
int _a[6][3] = {
  {9,3,1},
  {9,1,3},
  {3,9,1},
  {3,1,9},
  {1,9,3},
  {1,3,9}
};

int bfs(int a,int b,int c)
{
  visited[a][b][c] = 1;
  pos.push({a,b,c});

  while(!pos.empty())
  {
    int a = pos.front().a;
    int b = pos.front().b;
    int c = pos.front().c;

    pos.pop();

    if(visited[0][0][0])
      break;

    for(int i =0;i<6;i++)
    {
      int na = max(0,a - _a[i][0]);
      int nb = max(0,b - _a[i][1]);
      int nc = max(0,c - _a[i][2]);
      if(!visited[na][nb][nc])
      {
        visited[na][nb][nc] = visited[a][b][c] + 1; // 이렇게 각 위치로 가는 최단거리를 update
        pos.push({na,nb,nc});
      }
    }
  }

  return visited[0][0][0] - 1;

}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  memset(visited,0,sizeof(visited));
  memset(a,0,sizeof(a));

  cin >> N;
  
  // 체력 입력 받음
  for(int i =0;i<N;i++)
  {
    cin >> a[i];
  }

  cout << bfs(a[0],a[1],a[2]) << "\n";

  return 0;
}