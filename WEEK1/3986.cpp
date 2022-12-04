#include<bits/stdc++.h> 
using namespace std;  

/*
  문제 로직을 정답과 똑같이 작성했었으나, 실행이 안됨.
  도저히 원인을 찾지 못해 일단 정답으로 제출
*/

int n, ret; 
string s; 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n; 
	for(int i = 0; i < n; i++){
		cin >> s; 
		stack<char> stk;
		for(char a : s){
			if(stk.size() && stk.top() == a)stk.pop();
			else stk.push(a); 
		} 
		if(stk.size() == 0)ret++;
	}
	cout << ret << "\n";
}