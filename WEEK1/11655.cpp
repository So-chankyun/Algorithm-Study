#include <iostream>
#include <vector>
#include <cctype>
#include <string>
using namespace std;

/*
  알파벳은 23개이다.
  encrypt(a) = (a+13) % 23
*/

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string sentance = "";
  getline(cin,sentance,'\n');

  vector<char> ret;

  // 대문자일 경우
  for(auto c : sentance)
  {
    // cout << to_string((((c-'A')+13) % 23)+'A') << ' ';

    if(isupper(c))
    {
      ret.push_back((((c-'A')+13) % 26)+'A');
    }
    else if(islower(c))
    {
      ret.push_back((((c-'a')+13) % 26)+'a');
    }
    else // 알파벳이 아닐경우 그냥 push
    {
      ret.push_back(c);
    }
  }
  
  for(auto c : ret)
  {
    cout << c;
  }

  return 0;
}