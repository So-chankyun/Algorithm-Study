#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n,m,r1,c1,r2,c2,cnt;
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};
char map[302][302];
int visited[302][302];
bool flag = false;
queue<pair<int,int>> q;

void bfs(int r,int c)
{
  visited[r][c] = 1;
  q.push({r,c});

  while(!q.empty())
  {
    int row = q.front().first; 
    int col = q.front().second;

    // * 인지 확인
    if(map[row][col] == '#')
    {
      // cout << "find!!" << endl;
      flag = true;
      break;
    }
    q.pop();

    for(int i = 0;i<4;i++)
    {
      int nr = row + dr[i];
      int nc = col + dc[i];

      if(nr < 1 || nc < 1 || nr > n || nc > m)
        continue;

      if(!visited[nr][nc])
      {
        visited[nr][nc] = 1;
        // 1인지 확인
        if(map[nr][nc] == '1')
        {
          map[nr][nc] = '0';
          continue;
        }
        // 0일 경우 next 진행
        q.push({nr,nc});
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  cin >> n >> m;
  cin >> r1 >> c1 >> r2 >> c2;

  for(int i =1;i<=n;i++)
  {
    for(int j = 1;j<=m;j++)
    {
      cin >> map[i][j];
    }
  }

  while(!flag)
  {
    memset(visited,0,sizeof(visited));
    visited[r1][c1] = 1;
    bfs(r1,c1);// 주난이의 좌표부터 시작 

    cnt++;

    // cout << "cnt : " << cnt << endl;

    // for(int i =1;i<=n;i++)
    // {
    //   for(int j = 1;j<=m;j++)
    //   {
    //     cout << map[i][j] << " ";
    //   }
    //   cout << "\n";
    // }
    // cout << "\n";

    // if(cnt == 4)
    //   break;
  }

  cout << cnt;
  
  return 0;
}