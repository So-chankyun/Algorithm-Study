// /*
// * 문제
// - input : M(y),N(x), K(직사각형 좌표 갯수) 가 주어짐
// - output : 첫째줄에는 나눠지는 영역의 갯수, 두번째 줄에는 각 영역의 넓이

// * 해결방안
// - 알고리즘
//   1. 각 좌표에 접근. 
//   2. 좌표 배열을 돌면서 분리된 영역의 합을 구함(DFS)
//   3. 한 번의 탐색이 끝났을 때 영역의 갯수를 +1 하고, 영역의 넓이를 저장
// */

#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
#include <algorithm>

using namespace std;

int M=0, N=0, K = 0;
int map[104][104] = {}; 
bool visited[104][104] = {};
vector<tuple<int,int,int,int>> points;
vector<pair<int,int>> delta = {{-1,0},{1,0},{0,-1},{0,1}}; // 상,하,좌,우

int dfs(int y,int x)
{
  visited[y][x] = true;

  int result = 1;
  
  for(int i = 0;i<4;i++)
  {
    int next_x=0,next_y=0;

    next_x = x+delta[i].first;
    next_y = y+delta[i].second;

    // 1. 경계에 있는지 확인해야함
    // 1.1 큰 사각형의 끝에 있는지?
    if(next_x >= N || next_y >= M || next_x < 0 || next_y <0)
      continue;

    // 2. 다음 장소 방문 여부 체크
    if(visited[next_y][next_x] == true) // 이미 방문했을 경우
      continue;

    if(map[next_y][next_x] == 1) 
      continue;
    
    result += dfs(next_y, next_x);
  }

  return result;
}

int main()
{
  cin >> M >> N >> K;

  for(int i = 0;i < K;i++)
  {
    int x1=0,x2=0,y1=0,y2 = 0;
    cin >> x1 >> y1 >> x2 >> y2;
    for(int x = x1;x<x2;x++)
    {
      for(int y = y1;y<y2;y++)
      {
        map[y][x] = 1;
      }
    }
  }
  
  vector<int> result;

  for(int i = 0;i<M;i++)
  {
    for(int j =0;j<N;j++)
    {
      if(!visited[i][j] && !map[i][j])      
        result.push_back(dfs(i,j));
    }
  }

  cout << result.size() << "\n";

  sort(result.begin(),result.end());

  for(int i =0;i < result.size();i++)
  {
    cout << result[i] << " "; 
  }

  return 0;
}