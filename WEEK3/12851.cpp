#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int MAX = 200000;
int visited[MAX+1];
int n, k;
long long time_log[MAX+1];
queue<int> q;

void find_sister()
{
  visited[n] = 1;
  time_log[n] = 1;

  q.push(n);

  while(!q.empty())
  {
    int p = q.front(); // 위치 정보
    q.pop();

    for(int next : {p+1, p-1,2*p})
    {
      if(0<= next && next <= MAX)
      {
        if(!visited[next])
        {
          q.push(next);      
          visited[next] = visited[p] + 1; // 시간의 증가를 기록
          time_log[next] += time_log[p]; // 경우의 수를 기록
        }else if(visited[next] == visited[p]+1) // 이미 방문을 했지만 동일 시간으로 방문할 수 있는 다른 정점이 있다면?
        {
          time_log[next] += time_log[p];
        }
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> k;

  // 반례
  if(n == k)
  {
    puts("0"); puts("1");
    return 0; 
  }
  else
  {
    find_sister();

    cout << visited[k] - 1 << '\n';
    cout << time_log[k] << '\n';
  }


  return 0;
}