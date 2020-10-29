//https://practice.geeksforgeeks.org/problems/word-break/0#
#include<string>
#include<iostream>
#include<unordered_set>
using namespace std;

unordered_set<string> dict;

bool recur(string s){
  int size = s.size();
  if(size==0) return true;
  bool mem[size+1];
  for(int i=0;i<size+1;i++) mem[i]=0;

  for(int i=1;i<=size;i++){
    if(mem[i]==false && dict.find(s.substr(0,i))!=dict.end())
      mem[i]=true;

    if(mem[i]==true){
      if(i==size) return true;

      for(int j=i+1;j<=size;j++){
        if(mem[j]==false && dict.find(s.substr(i,j-i))!=dict.end())
          mem[j]=true;

        if(j==size && mem[j]==true) return true;
      }
    }
  }
  return false;
}

void solve(){
  dict.clear();
  int n; cin >> n;
  for(int i=0;i<n;i++){
    string temp; cin >> temp;
    dict.insert(temp);
  }
  string s;
  cin >> s;
  cout << recur(s) << "\n";
}

int main(){
  int T; cin >> T;
  while(T--){
    solve();
  }
}
