#include <iostream>
#include <string>
using namespace std;

/*
  (a+b) % n = (a % n + b % n) % n
  (a*b) % n = (a % n * b % n) % n
  굳이 마지막 숫자까지 가서 모듈러 연산을 하지 말고 중간 중간 숫자를 나눠서 모듈러 연산을 해도 됨.

*/

int main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  // 숫자 입력
  int n;
  int count = 1;
  int num = 1;  

  cin >> n;

  while(true)
  {
    if(num % n == 0)
    {
      cout << count << '\n';
      break;
    }
    else
    {
      num = (num*10) + 1;
      num %= n;
      count++;
    }
  }

  return 0;
}

