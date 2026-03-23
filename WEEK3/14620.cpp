#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int n;
int map[12][12];
int visited[12][12];
int min_cost = 3001;
int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};

int cal_cost(int row, int col)
{
  int cost = map[row][col];

  for(int i =0;i<4;i++)
  {
    int nr = row + dr[i];
    int nc = col + dc[i];

    cost += map[nr][nc];
  }

  return cost;
}

bool check_out(int row, int col)
{
  bool flag = false;

  for(int i =0;i<4;i++)
  {
    int nr = row + dr[i];
    int nc = col + dc[i];

    if(nr < 1 || nc < 1 || nr > n || nc > n)
    {
      flag = true;
    }
  }

  return flag;
}

void find_min_cost(int row, int col, int cost,vector<pair<int,int>> arr)
{
  // 기저 사례(depth 가 3인 경우)
  if(arr.size() == 3)
  {
    // 꽃잎이 서로 겹치는지 확인. 각 꽃잎의 중심 거리를 구한다.
    int dist1 = abs(arr[0].first - arr[1].first) + abs(arr[0].second - arr[1].second);
    int dist2 = abs(arr[0].first - arr[2].first) + abs(arr[0].second - arr[2].second);
    int dist3 = abs(arr[1].first - arr[2].first) + abs(arr[1].second - arr[2].second);
    
    // 3보다 작으면 꽃잎이 겹치게됨
    if(dist1 < 3 || dist2 < 3 || dist3 < 3)
    {
      // cout << "overlap\n";
      return;
    }

    // for(int i =0;i<3;i++)
    // {
    //   cout << "pos : "<< arr[i].first << ", " << arr[i].second << "\n";
    // }
      
    // 최소 비용 비교
    // if(cost < min_cost)
    // {
    //   for(int i =0;i<3;i++)
    //   {
    //     cout << "pos : "<< arr[i].first << ", " << arr[i].second << "\n";
    //   }

    //   cout << "cost : " << cost << "\n";
    // }

    min_cost = min(min_cost, cost);  

    return;
  }

  // 탐색
  for(int i =1;i<=n;i++)
  {
    for(int j =1;j<=n;j++)
    {
      // 이미 방문했는가? 해당 지점의 꽃잎이 map 을 안벗어나는가?
      if(!visited[i][j] && !check_out(i,j))
      {
        arr.push_back({i,j});
        visited[i][j] = 1;
        find_min_cost(i,j,cost+cal_cost(i,j),arr);
        visited[i][j] = 0;
        arr.pop_back();
        }
    } 
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;

  for(int i =1;i<=n;i++)
  {
    for(int j =1;j<=n;j++)
    {
      cin >> map[i][j];
    }
  }

  vector<pair<int,int>> a;

  find_min_cost(1,1,0,a);

  cout << min_cost;

  return 0;
}