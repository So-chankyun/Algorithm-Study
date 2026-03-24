#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 200004;
int visited[MAX];
int pre[MAX];
int n,k;
vector<int> v;

void find_path()
{
  visited[n] = 1;
  queue<int> q;
  q.push(n);

  while(!q.empty())
  {
    int p = q.front();
    q.pop();

    // 기저사례
    if(p == k)
    {
      break;
    }

    for(int next : {p+1, p-1, 2*p})
    {
      // cout << "next : " << next << "\n";
      // 벗어나는지 확인
      if(next < 0 || next >= MAX)
        continue;

      // 방문여부 확인
      if(!visited[next])
      {
        visited[next] = visited[p]+1; // 시간을 기록
        q.push(next);
        pre[next] = p;
      }
    }
  }

  for(int i = k;i != n;i = pre[i])
  {
    v.push_back(i);
  }
  v.push_back(n);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> k;

  if(n == k)
  {
    cout << "0\n"<< n;
    return 0;
  }

  find_path();

  cout << visited[k] - 1 << "\n";

  reverse(v.begin(),v.end());

  for(int i : v)
  {
    cout << i << " ";
  }

  return 0;
}