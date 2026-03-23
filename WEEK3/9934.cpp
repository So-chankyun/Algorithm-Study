#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int k;
vector<int> nodes;

void search(int target, int depth, int left, int right)
{
  int mid = (left + right) / 2;

  // depth 체크
  if(target == depth)
  {
    cout << nodes[mid] << " ";
    return;
  }

  int new_right = mid - 1;
  int new_left = mid + 1; 

  // 왼쪽 노드 탐색
  search(target, depth+1, left, new_right);
  
  // 오른쪽 노드 탐색
  search(target, depth+1, new_left, right);  
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> k;
  
  for(int i =0;i<pow(2,k)-1;i++)
  {
    int n = 0;
    cin >> n;
    nodes.push_back(n);
  }

  // search
  for(int i =0;i<k;i++)
  {
    search(i,0,0,nodes.size()-1);
    cout << "\n";
  }

  return 0;
}