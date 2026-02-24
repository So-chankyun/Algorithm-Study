#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<int,int> idx; // <input, idx>
vector<pair<int,int>> arr(1001); // <input, count>
int N,C = 0;

bool cmp(pair<int,int> a, pair<int,int> b)
{
  return a.second > b.second;
}

int main()
{
  cin.tie();
  ios_base::sync_with_stdio(0);

  cin >> N >> C;

  for(int i = 0;i<N;i++)
  {
    int num = 0;

    cin >> num;

    if(idx.find(num) == idx.end())
    {
      arr.push_back({num,1});
      idx[num] = arr.size()-1;
    }
    else
    {
      arr[idx[num]].second++;
    }
  }

  stable_sort(arr.begin(),arr.end(),cmp);

  for(int i =0;i<N;i++)
  {
    for(int j =0;j<arr[i].second;j++)
    {
      cout << arr[i].first << " ";
    }
  }

  return 0;
}