#include <iostream>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N = 0;
  string pattern = "";

  cin >> N;
  cin >> pattern;

  int star_idx = pattern.find('*');
  string pre = pattern.substr(0,star_idx);
  string suf = pattern.substr(star_idx+1);

  for(int i =0;i<N;i++)
  {
    string str = "";
    cin >> str;
    
    // 주어진 string이 pattern보다 짧은 경우
    if(pre.size()+suf.size() > str.size())
    {
      cout << "NE" << '\n';
      continue;
    } // prefix suffix가 모두 같은 경우

    if((pre == str.substr(0,pre.length())) && (suf == str.substr(str.length()-suf.length())))
    {
      cout << "DA" << '\n';
    }
    else
      cout << "NE" << '\n';
  }
  
  return 0;
}