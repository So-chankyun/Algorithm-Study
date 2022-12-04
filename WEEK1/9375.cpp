#include <iostream>
#include <map>
using namespace std;

/*
  모든 경우의 수를 구한다음 공집합을 빼준다.
*/
int T,N;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> T;

  for(int i = 0;i<T;i++)
  {
    cin >> N;
    map<string,int> c;

    for(int j =0;j<N;j++)
    {
      string a, b;

      cin >> a >> b;
      c[b]++;
    }

    int ret = 1;
    
    for(auto a : c)
      ret *= (a.second+1);

    cout << ret-1 << '\n';
  }
  return 0;
}