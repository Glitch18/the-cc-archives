//https://practice.geeksforgeeks.org/problems/longest-valid-parentheses/0
#include <iostream>
#include<stack>
#include<string>
using namespace std;

void solve(){
    string s;
    cin >> s;
    stack<int> stk;
    stk.push(-1);
    int count = 0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(') stk.push(i);
        else if(s[i]==')'){
            if(!stk.empty()) stk.pop();
            if(!stk.empty()) count = max(count,i-stk.top());
            else stk.push(i);
        }
    }
    cout << count << "\n";
}

int main() {
	int T; cin >> T;
	while(T--){
	    solve();
	}
	return 0;
}
