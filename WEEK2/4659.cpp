/*
  - 특정 문자열이 주어졌을 때 문자열을 평가
  - end가 입력 되면 평가 종료
*/

#include <iostream>
#include <string>
#include <set>
using namespace std;

bool contain_any(string& s, string& chars)
{
  return s.find_first_of(chars) == string::npos;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  string s = "aeiou";

  while(true)
  {
    string pw = "";

    bool total_flag = true;
    
    cin >> pw;

    // 탈출조건
    if(pw == "end")
      break;
    
    // 1. 모음 하나 포함하는지 체크(없다면?)
    if(contain_any(pw,s))
    {
      total_flag = false;
    }

    // 2. 3연속 자음인지, 모음인지 확인
    int cnt = 0; // 연속 카운트
    bool flag = true; // 모음    

    for(int i =0;i<pw.size();i++)
    {
      // 모음인 경우
      if(s.find(pw[i]) != string::npos)
      {
        if(!flag)
        {
          flag = true;
          cnt = 0;
        }
        
        cnt++;
      }
      else
      {
        if(flag)
        {
          flag = false;
          cnt = 0;
        }

        cnt++;
      }
      
      if(cnt >= 3)
      {
        total_flag = false;
        break;
      }
    }

    // 3. 같은 글자가 연속으로 두번 오면 안되나, ee와 oo는 허용
    for(int i = 1;i<pw.size();i++)
    {
      if(pw[i] == pw[i-1])
      {
        if(pw[i] == 'e' || pw[i] == 'o')
        {
          continue;
        }  
        else
        {
          total_flag = false;
          break;
        }
      }
    }

    if(total_flag)
    {
      cout << "<" << pw << ">" << " is acceptable." << "\n";
    }
    else
    {
      cout << "<" << pw << ">" << " is not acceptable." << "\n";
    }
  }

  return 0;
}