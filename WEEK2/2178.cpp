// // /*

// // */

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

const int max_n = 104;
int N,M;
int moved[4][2] = {{-1,0},{1,0},{0,-1},{0,1}}; // 상,하,좌,우
int map[max_n][max_n];
int visited[max_n][max_n];

void bfs()
{
    queue<pair<int,int>> q;
    visited[0][0] = 1;
    q.push({0,0});

    while(!q.empty())
    {
        pair<int,int> pos = q.front();
        int y = pos.first;
        int x = pos.second;
        q.pop();

        for(int i =0;i<4;i++)
        {
            // 다음 좌표 설정
            int nx_y = y+moved[i][0];
            int nx_x = x+moved[i][1];
            
            // map을 벗어나는지 확인
            if(nx_y < 0 || nx_y >= N || nx_x < 0 || nx_x >= M || map[nx_y][nx_x]==0)
                continue;

            // 방문했는지 확인
            if(visited[nx_y][nx_x] == 0)
            {
                q.push({nx_y,nx_x});
                
                visited[nx_y][nx_x] = visited[y][x] + 1;
            }
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M); 
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf("%1d", &map[i][j]);
        }
    } 

    bfs();

    printf("%d",visited[N-1][M-1]);
    return 0;
}

