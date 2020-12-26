//https://codeforces.com/problemset/problem/1462/B
#include<bits/stdc++.h>
using namespace std;

/*
#2020
2#020
20#20
202#0
2020#
*/

int main(){
    int T; cin >> T;
    while(T--){
        int len; cin >> len;
        string s; cin >> s;
        if(s.compare(0,4,"2020") == 0) cout << "YES\n";
        else if(s.compare(s.size()-3,3,"020")==0 && s[0]=='2') cout << "YES\n";
        else if(s.compare(0,2,"20")==0 && s.compare(s.size()-2,2,"20")==0)
          cout << "YES\n";
        else if(s.compare(0,3,"202")==0 && s[s.size()-1]=='0') cout << "YES\n";
        else if(s.compare(s.size()-4,4,"2020")==0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
