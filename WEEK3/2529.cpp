#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int k;
vector<char> e; // 부등호 리스트
vector<vector<int>> combi_list; // 조합 리스트
int n[10] = {0,1,2,3,4,5,6,7,8,9};
long long max_val = -1;
long long min_val = 9999999999;

void combi(int start, vector<int> arr)
{
  if(arr.size() == (k+1))
  {
    combi_list.push_back(arr);
    return;
  }

  for(int i = start + 1;i<10;i++)
  {
    arr.push_back(i);
    combi(i,arr);
    arr.pop_back();
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> k;
  
  for(int i =0;i<k;i++)
  {
    char temp;
    cin >> temp;
    e.push_back(temp);
  }

  // 조합 진행
  vector<int> arr;

  for(int i =0;i<10-k;i++)
  {
    arr.push_back(i);
    combi(i,arr);
    arr.clear();
  }
  
  for(vector<int> a : combi_list)
  {
    sort(a.begin(),a.end());

    // 각 조합별로 permutation 을 진행하면서 부등호에 맞는지 확인  
    do{
      bool flag = false;

      for(int i =0;i<k+1;i++)
      {
        // 각 부등호에 맞는지 확인
        if(e[i] == '<')
        {
          // 조건을 만족한다면 continue
          if(a[i] >= a[i+1])
            break;
        }
        else // e[i] == '>'
        {
          if(a[i] <= a[i+1])
            break;
        }

        // 모든 조건을 만족할 경우
        if(i == (k-1)) 
          flag = true;
      }

      // min, max update
      if(flag)
      {
        string temp = "";
        // 숫자로 변환
        for(int i = 0;i<a.size();i++)
        {
          temp += (a[i] + '0'); // 글자로 변경
        }
        
        long long num = stoll(temp); // 합쳐진 문자를 숫자로 다시 변환

        // update
        min_val = min(num,min_val);
        max_val = max(num,max_val);
      }
    }while(next_permutation(a.begin(),a.end()));
  }
  
  printf("%0*lld\n",k+1,max_val);
  printf("%0*lld",k+1,min_val);

  return 0;
}