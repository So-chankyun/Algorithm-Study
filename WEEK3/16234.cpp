#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

int N=0,L=0,R=0;
int map[51][51];
bool visited[51][51];
int d[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int n =0,sum;
vector<pair<int,int>> pos;

// find connected component
void dfs(int row, int col)
{
  for(int i=0;i<4;i++)
  {
    int n_row = row + d[i][0];
    int n_col = col + d[i][1];
    
    if(n_row < 0 || n_col < 0 || n_row >= N || n_col >= N)
    {
      continue;
    }
    
    int gap = abs(map[row][col] - map[n_row][n_col]);

    if(!visited[n_row][n_col] && (gap >= L && gap <= R))
    {
      visited[n_row][n_col] = true;
      pos.push_back({n_row,n_col});
      sum += map[n_row][n_col];
      dfs(n_row,n_col);      
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  memset(map,0,sizeof(map));

  cin >> N >> L >> R;

  for(int i = 0;i<N;i++)
  {
    for(int j = 0;j<N;j++)
    {
      cin >> map[i][j];
    }  
  }

  while(true)
  {
    memset(visited,0,sizeof(visited));
    bool cc = false;

    for(int i = 0;i<N;i++)
    {
      for(int j = 0;j<N;j++)
      {
        if(!visited[i][j])
        {
          pos.clear();
          visited[i][j] = true;
          pos.push_back({i,j});
          sum = map[i][j];

          // 연결 요소 찾고 합구하기
          dfs(i,j);
          
          if(pos.size() == 1)
            continue;

          // 각 나라의 인구수 업데이트
          for(pair<int,int> p:pos)
          {
            map[p.first][p.second] = sum / pos.size();
            cc = true;
          }
        }
      }  
    }
    
    // 연결요소가 하나도 없는 경우
    if(cc == false)
      break;

    n++;
  }

  cout << n;

  return 0;
}