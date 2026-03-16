#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int N;
int score_a=0,score_b=0;
int s1,s2;
vector<string> time_info;
map<string,pair<int,int>> score_info;
int win_time_a =0, win_time_b=0;

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> N;

  for(int i =0;i<N;i++)
  {
    int team = 0;
    string time = "";

    cin >> team >> time;
    
    if(team == 1)
    {
      score_a++;
    }
    else{
      score_b++;
    }
    
    time_info.push_back(time);
    score_info.insert({time,{score_a,score_b}});  
  }

  // 종료시간 push
  time_info.push_back("48:00");
  score_info.insert({"48:00",{score_a,score_b}});

  // 승리 시간 count
  for(int i = 1;i<time_info.size();i++)
  {
    // 현재 시간까지 누가 이기고 있었는지 확인
    int temp_a = score_info[time_info[i-1]].first;
    int temp_b = score_info[time_info[i-1]].second;

    string now_time = time_info[i];
    string before_time = time_info[i-1];

    // 초로 변환
    s2 = stoi(now_time.substr(0,2)) * 60 + stoi(now_time.substr(3));
    s1 = stoi(before_time.substr(0,2)) * 60 + stoi(before_time.substr(3));

    // a가 이기고 있었을 경우
    if(temp_a > temp_b)
      win_time_a += s2-s1;
    else if(temp_a < temp_b)
      win_time_b += s2-s1;
  }

  // 각 팀의 승리 시간 출력
  int win_m1 = win_time_a / 60;
  int win_s1 = win_time_a % 60;
  
  int win_m2 = win_time_b / 60;
  int win_s2 = win_time_b % 60;

  printf("%02d:%02d\n",win_m1,win_s1);
  printf("%02d:%02d\n",win_m2,win_s2);

  return 0;
}