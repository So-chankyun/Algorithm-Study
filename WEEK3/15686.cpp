#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

int map[51][51];
int N = 0,M=0;
vector<pair<int,int>> homes; // 집 좌표 리스트
vector<pair<int,int>> chickens; // 치킨집 좌표 리스트
vector<vector<int>> chList; // 치킨집 조합 리스트
int result = 987654321;

// 치킨집을 고르는 조합을 수행
void combi(int start, vector<int> v)
{
  // 만약 v 의 사이즈가 m 과 동일하다면 return
  if(v.size() == M)
  {
    chList.push_back(v);
    return;
  }

  for(int i = start + 1;i<chickens.size();i++)
  {
    v.push_back(i);
    combi(i,v);
    v.pop_back();
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  memset(map,0,sizeof(map));

  cin >> N >> M;

  // 지도 채우기
  for(int i =0;i<N;i++)
  {
    for(int j =0;j<N;j++)
    {
      cin >> map[i][j];
      
      if(map[i][j] == 1)
        homes.push_back({i,j});
      else if(map[i][j] == 2)
        chickens.push_back({i,j});
    }
  }

  vector<int> v;
  combi(-1,v);

  // 각 치킨집 조합을 돌면서 집과의 거리를 계산하고, 최소 거리를 구한다.
  for(vector<int> comb : chList)
  {
    int ret = 0;
    
    for(pair<int,int> home : homes)
    {
      int _min = 987654321;
      // 각 치킨집을 돌면서 집과의 거리를 측정
      for(int i : comb)
      {
        int dist = abs(home.first-chickens[i].first) + abs(home.second-chickens[i].second);
        _min = min(_min,dist);
      }

      ret += _min;
    }
    result = min(result,ret);
  }

  cout << result << "\n";

  return 0;
}