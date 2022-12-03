#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

/*
  문제가 알파벳으로만 들어오면 포켓몬 번호를 발해야 하고, 숫자로만 들어오면, 포켓몬 번호에 해당하는 문자를 출력해야함.
  입력을 들어오는 숫자는 반드시 1보다 크거나 같고, N보다 작거나 같고, 입력으로 들어오는 문자는 반드시 도감에 있는 포켓몬의 이름만 주어짐
*/


vector<string> name;
map<string,int> name_to_int;

bool isNumber(const string& str)
{
  for(char const &c:str)
  {
    if(isdigit(c) == 0)
    {
      return false;
    }
  }
  return true;
}


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N,M;
  cin >> N >> M;

  for(int i = 0;i<N;i++)
  {
    string n = "";
    cin >> n;
    name.push_back(n);
    name_to_int[n] = i+1;
  }

  for(int i =0;i<M;i++)
  {
    string q = "";

    cin >> q;

    // 숫자인지 판단
    if (isNumber(q))
    {
      cout << name[stoi(q)-1] << '\n';
    }
    else
    {
      cout << name_to_int[q] << '\n'; 
    }
  }

  return 0;
}