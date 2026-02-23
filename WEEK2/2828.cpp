#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// map 선언
vector<int> screen(11);
vector<int> pos(21);

// 변수 선언
int N,M,j = 0;

int main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> N >> M;
  cin >> j;

  int start_idx = 1;
  int end_idx = 0;
  int min_dist = 0;

  for(int i =0;i<j;i++)
  {
    cin >> pos[i];
    pos.push_back(pos[i]);
  }

  for(int i =0; i<j;i++)
  {
    end_idx = start_idx + M - 1;

    // 1. 바구니의 범위에 있는지 확인
    if(pos[i] >= start_idx && pos[i] <= end_idx) // 바구니에 있는 경우
    {
      continue;
    }
    // end_idx < pos
    else if(end_idx < pos[i])
    {
      min_dist += pos[i] - end_idx;
      start_idx += pos[i] - end_idx;
    }
    // pos < start_idx
    else if(pos[i] < start_idx)
    {
      min_dist += start_idx - pos[i];
      start_idx = pos[i];
    }    
  }

  cout << min_dist << "\n";

  return 0;
}