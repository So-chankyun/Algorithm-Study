#include <iostream>
#include <algorithm>
using namespace std;

const int EXP_MAX = 31;

int N,T;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> T;

  for(int i =0;i<T;i++)
  {
    int a =0 ,b = 0; // 2의 지수승, 5의 지수승
    cin >> N;

    for(int j =2;j<=N;j *=2)
    {
      a += N / j;
    }

    for(int j =5;j<=N;j *=5)
    {
      b += N / j;
    }
    
    cout << min(a,b) << "\n";
  } 

  return 0;
}