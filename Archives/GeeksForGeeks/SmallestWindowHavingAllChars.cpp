//https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string/0
#include <iostream>
#include<string>
#include<limits.h>
using namespace std;

int MAX_CHAR = 256;

void solve(){
    string s,t;
    cin >> s >> t;
    if(s.length()<t.length()){
        cout << "-1\n";
        return;
    }

    int hash_s[MAX_CHAR]={0};
    int hash_t[MAX_CHAR]={0};

    int start = 0, start_index=-1, min_len=INT_MAX;
    int count=0;
    for(auto i:t) hash_t[i]++;

    for(int i=0;i<s.length();i++){
        hash_s[s[i]]++;

        if(hash_t[s[i]]!=0 && hash_s[s[i]]<=hash_t[s[i]]) count++;

        if(count==t.length()){
            while(hash_t[s[start]]==0 || hash_s[s[start]] > hash_t[s[start]]){
                if(hash_s[s[start]] > hash_t[s[start]])
                    hash_s[s[start]]--;
                start++;
            }

            int new_len = i-start+1;
            if(new_len<min_len){
                min_len = new_len;
                start_index = start;
            }
        }
    }

    if(start_index==-1){
        cout << "-1\n";
        return;
    }

    cout << s.substr(start_index,min_len) << "\n";
    return;
}

int main() {
	int T; cin >> T;
	while(T--){
	    solve();
	}
	return 0;
}
