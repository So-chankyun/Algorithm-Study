#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
  온도가 어떤 정수의 수열로 주어졌을 때, 연속적인 며칠 동안의 온도의 합이 가장 큰 값을 알아보고자 한다.
  매일 측정한 온도가 정수의 수열로 주어졌을 때, 연속적인 며칠 동안의 온도의 합이 가장 큰 값을 계산하는 프로그램을 작성하시오.
  전형적인 누적합 문제

*/

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N,K;

  cin >> N >> K;

  vector<int> cumsum(N+4,0);

  for(int i =1;i<=N;i++)
  {
    int temp = 0;
    cin >> temp;
    cumsum[i] = cumsum[i-1]+temp;
  }

  int max_temp = -654321;

  for(int i = K;i<=N;i++)
  {
    max_temp = max(max_temp,cumsum[i]-cumsum[i-K]);
  }

  cout << max_temp << '\n';

  return 0;
}