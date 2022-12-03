#include <iostream>
#include <cstring>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int alphabet[30] = {0};
  string word = "";

  cin >> word;

  for(auto a : word)
  {
	int idx = a-'a';
	alphabet[idx]++;
  }

  for(int i =0;i<26;i++)
  {
	cout << alphabet[i] << ' ';
  }

  return 0;
}