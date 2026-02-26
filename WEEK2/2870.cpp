#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N; // 줄의 갯수
vector<string> num_arr; 
string numbers = "0123456789";

// 문자열에서 0을 제거
string substring(string t)
{
  int idx = 0; // 0이 아닌 최초 idx 를 저장

  for(int i = 0;i<t.size();i++)
  {
    if(t[i] != '0')
    {
      idx = i;
      break;
    }
    else if((t.size()-1 == i) && (t[t.size()-1] =='0'))
      idx = t.size()-1;
  }

  return t.substr(idx);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;

  for(int i=0;i<N;i++)
  {
    string s = "";
    cin >> s;
    
    string temp = "";

    for(int j =0;j<s.size();j++)
    {
      // 각 글자가 숫자인가? 그리고 0이 아니어야함.
      if((numbers.find(s[j]) != string::npos))
      {
        temp += s[j];
        
        // 마지막인 경우
        if((temp.size() > 0) && (s.size()-1 == j))
        {
          if(temp.size() > 1)
          {
            temp = substring(temp);
          }

          num_arr.push_back(temp);
        }
          
      } // 숫자가 아닌 경우
      else
      {
        if(temp != "")
        {          
          if(temp.size() > 1)
          {
            temp = substring(temp);
          }     
          
          num_arr.push_back(temp);
          // 초기화
          temp = "";
        }
      }
    }
  }

  if(num_arr.size() > 0)
  {
    sort(num_arr.begin(), num_arr.end(),
        [](const string& a, const string& b){
          if(a.size() != b.size()) // 문자열의 길이가 다를 경우 
            return a.size() < b.size(); // 사전식으로 내림 차순 정렬
          return a < b; // 문자열의 길이가 같을 경우 사전식으로 오름 차순 정렬
        });

    for(int i =0;i<num_arr.size();i++)
    {
      cout << num_arr[i] << "\n";
    }
  }

  return 0;
}