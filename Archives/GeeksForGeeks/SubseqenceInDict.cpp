//https://practice.geeksforgeeks.org/problems/find-largest-word-in-dictionary/0
#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool isSubseq(string s1,string s2){
    int sz1 = s1.length();
    int sz2 = s2.length();
    int j=0;

    for(int i=0;i<sz2&&j<sz1;i++){
        if(s1[j]==s2[i]) j++;
    }

    return (j==sz1);
}

bool compare(string s1,string s2){
    return (s1.length() > s2.length());
}

void solve(){
    int x; cin >> x;
    vector<string> dict;
    for(int i=0;i<x;i++){
        string temp; cin >> temp;
        dict.push_back(temp);
    }
    string str; cin >> str;
    sort(dict.begin(),dict.end(),compare);

    for(auto i:dict){
        if(isSubseq(i,str)){
            cout << i << "\n";
            return;
        }
    }
    return;
}

int main() {
	int T; cin >> T;
	while(T--){
	    solve();
	}
	return 0;
}
