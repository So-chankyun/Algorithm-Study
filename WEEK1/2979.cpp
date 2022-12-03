#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int a,b,c;
  int max_time = 0;
  int min_time = 101;
  vector<pair<int,int>> timeInterval;
  vector<int> time(101);

  cin >> a >> b >> c;

  for(int i =0;i<3;i++)
  {
    int start, last;
    cin >> start >> last;
    timeInterval.push_back({start,last});
    max_time = max(last,max_time);
    min_time = min(start,min_time);
  }
  
  // 일단 돌면서 각 시간대의 차량의 갯수를 구한다.
  // 시간의 maximum을 24라고 생각하자
  for(int i = min_time;i<=max_time;i++)
  {
    for(auto interval : timeInterval)
    {
      // 만약 i가 주어진 시간간격 안에 존재한다면?
      if((i >= interval.first) && (i < interval.second))
      {
        time[i]++;
      }
    }
  }

  int fee = 0;

  for(int i = min_time;i<=max_time;i++)
  {
    // cout << i << " : " << time[i] << '\n';

    if(time[i] == 1)
      fee += time[i]*a;
    else if(time[i] == 2)
      fee += time[i]*b;
    else if(time[i] == 3)
      fee += time[i] * c;
  }

  cout << fee;

  return 0;
}