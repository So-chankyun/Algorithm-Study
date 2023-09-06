/*
bfs를 여러번 돌리면 될 듯 하다.
*/

#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int max_n = 53;
int N,M,T,K,min_num,leaf,x,y;
int map[max_n][max_n];
int visited[max_n][max_n];
int moved[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

int bfs(int y,int x, int leaf)
{
  queue<pair<int,int>> q;
  visited[y][x] = 1;
  q.push({y,x});
  
  while(q.size())
  {
    pair<int,int> pos = q.front();

    int pos_x = pos.second;
    int pos_y = pos.first;
    
    q.pop();

    for(int i =0;i<4;i++)
    {
      int ny = pos_y+moved[i][0];
      int nx = pos_x+moved[i][1];

      // printf("%d %d\n",ny,nx);

      if(ny < 0 || ny >= N || nx < 0 || nx >= M || map[ny][nx] == 0)
        continue;

      // 아직 방문하지 않았다면?
      if(!visited[ny][nx])
      {
        // printf("%d %d\n",ny,nx);
        q.push({ny,nx});
        visited[ny][nx] = 1;
        leaf++;
      }
    }
  }

  return leaf;
}

int main()
{
  scanf("%d",&T);

  for(int i =0;i<T;i++)
  {
    memset(map,0,sizeof(map));
    memset(visited,0,sizeof(visited));
    min_num = 0; // 최소 지렁이 수
    leaf = 0; // 배추 갯수

    cin >> N >> M >> K;

    // map 생성
    for(int j =0;j<K;j++)
    {
      int pos_x,pos_y;

      cin >> pos_y >> pos_x;
      map[pos_y][pos_x] = 1;
    }

    // 배추 탐색 및 지렁이 카운팅
    for(int j =0;j<N;j++)
    {
      for(int k = 0;k<M;k++)
      {
        // 배추가 없거나 이미 방문한 곳은 지나침
        if(map[j][k] == 0 || visited[j][k] == 1)
          continue;
        
        // 배추 다 찾으면 나간다
        if(leaf <= K)
        {
          leaf = bfs(j,k,leaf);
          min_num++;
          // printf("%d, (%d %d), min_num : %d\n",leaf,j,k,min_num);
        }
      }
    }
    
    printf("%d\n",min_num);
  }
  return 0;
}