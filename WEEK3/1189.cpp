#include <iostream>

using namespace std;
int map[6][6];
int visited[6][6];
int r,c,k,cnt;
int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};

void find_path(int row, int col, int dist)
{
  // 기저 사례, 도착지점에 도착했으면서 dist 가 k 인 경우
  if(dist == k && (row == 0) && (col == c-1))
  {
    // cout << dist << "\n";
    cnt++;
    return;
  }

  for(int i =0;i<4;i++)
  {
    int nr = row + dr[i];
    int nc = col + dc[i];

    // 나가는지 확인
    if(nr < 0 || nc < 0 || nr >= r || nc >= c)
      continue;

    // 방문했는지 확인 & T가 아닌지 확인해야함
    if(!visited[nr][nc] && (map[nr][nc] != 'T'))
    {
      visited[nr][nc] = 1;
      find_path(nr,nc,dist+1);
      visited[nr][nc] = 0;
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(); cout.tie(0);

  cin >> r >> c >> k;

  for(int i =0;i<r;i++)
  {
    string temp = "";
    cin >> temp;

    for(int j =0;j<c;j++)
    {
      map[i][j]= temp[j];
    }
  }

  visited[r-1][0] = 1;

  find_path(r-1, 0, 1);

  cout << cnt;

  return 0;
}