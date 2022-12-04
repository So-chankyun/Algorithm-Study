#include <iostream>
#include <vector>
using namespace std;

/*
  갑옷을 만드는 재료들은 각각 고유한 번호를 가지고 있다. 갑옷은 두 개의 재료로 만드는데 두 재료의 고유한 번호를 합쳐서 M
  이 되면 갑옷이 만들어진다. 
  N개의 재료와 M이 주어졌을 때 몇 개의 갑옷을 만들 수 있는지를 구하는 프로그램을 만들어라
  전형적인 combination 문제

  풀이:
    처음에는 재귀로 조합을 구현하여 풀었다. 하지만 이 과정에서 함수호출로 인한 시간 소모가 있어 시간 초과가 난듯 싶다.
    그래서 이를 반복문으로 다시 변경하였고, 시간초과가 발생하지 않았다.
    +고유한 번호는 최대 100000이다. 따라서 두 재료의 고유한 번호를 더하면 200000을 넘지 않는다. 넘는 경우에는 어차피 만들 수 없으므로
    0을 출력하도록 한다.
*/
int N,M;
int num = 0;
vector<int> c_num;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  cin >> M;

  for(int i =0;i<N;i++)
  {
    int n = 0;
    cin >> n;
    c_num.push_back(n);
  }

  if(M > 200000)
    cout << 0 << '\n';
  else{
    for(int i =0;i<N;i++)
    {
      for(int j = i+1;j<N;j++)
      {
        if(c_num[i]+c_num[j] == M)
          num++;
      }
    }

    cout << num << '\n';
  }
  


  return 0;
}