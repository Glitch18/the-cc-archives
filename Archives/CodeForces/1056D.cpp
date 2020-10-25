//https://codeforces.com/problemset/problem/1056/D
//Attempting a second submission for this problem
//based on my first submission from a year ago
//for a refresher
#include<iostream>
#include<unordered_map>
#include<map>
#include<vector>
using namespace std;

vector<int> adj[100001];
unordered_map<int,int> colors;
unordered_map<int,int> happy;
map<int,int> ans;

void dfs(int V,int pV){
  int numberOfColors=0;
  for(auto i : adj[V]){
    if(i==pV) continue;
    dfs(i,V);
    numberOfColors += colors[i];
  }
  if(V==1) colors[V] = (!adj[V].size()) ? 1 : numberOfColors;
  else if(adj[V].size()>1) colors[V] = numberOfColors;
  else colors[V] = 1;
}

int main(){
  int N;
  cin >> N;
  for(int i=2;i<=N;i++){
    int x;
    cin >> x;
    adj[x].push_back(i);
    adj[i].push_back(x);
  }
  dfs(1,0);
  for(int i=1;i<=N;i++) happy[colors[i]]++;
  for(int i=2;i<=N;i++) happy[i] += happy[i-1];
  for(auto i : happy){
    if(!ans[i.second]) ans[i.second] = i.first;
    else if(ans[i.second]>i.first) ans[i.second] = i.first;
  }
  for(int i=1;i<=N;i++) cout << (*ans.lower_bound(i)).second << " ";
}
