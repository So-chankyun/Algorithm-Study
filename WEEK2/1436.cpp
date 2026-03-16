#include <iostream>
#include <string>
using namespace std;

int N;

bool find_six(string num)
{
  bool flag = false;
  int cnt = 0;

  // 연속된 6을 찾아야함..
  for(int i = 0;i<num.size();i++)
  {
    if((num[i] == '6') && (num[i+1] == '6') && (num[i+2] == '6'))
    {
      flag = true;
      break;
    }
  }

  return flag;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;

  int cnt = 1;
  int i = 666;

  while(cnt < N)
  {
    string temp = to_string(++i);

    if(find_six(temp))
    {
      cnt++;
      // cout << "cnt : " << cnt << ", temp : " << temp << "\n";
    }
      
  }
  
  cout << i;

  return 0;
}