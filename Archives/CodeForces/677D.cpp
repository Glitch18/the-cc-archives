#include<iostream>
#include<stdio.h>
#include<unordered_map>
#include<vector>
using namespace std;

#define ll long long

unordered_map<int,vector<int>> matrix;
int n;

void solve(){
  cin >> n;
  for(int i=1;i<=n;i++){
    int gang;
    cin >> gang;
    matrix[gang].push_back(i);
  }

  if(matrix.size()==1){
    cout << "NO\n";
    matrix.clear();
    return;
  }

  cout << "YES\n";
  for(auto it = next(matrix.begin(),1);it!=matrix.end();it++){
    for(auto vec: it->second)
      cout << matrix.begin()->second[0] << " " << vec << "\n";
  }

  for(int i=1; i<matrix.begin()->second.size(); i++)
    cout << next(matrix.begin(),1)->second[0] << " " << matrix.begin()->second[i] << "\n";

  matrix.clear();
  return;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while(t--){
    solve();
  }
  return 0;
}
