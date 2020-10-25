#include<bits/stdc++.h>

int eu[int(1e5)],ev[int(1e5)], ans[int(1e5)];
std::basic_string<int> adj[int(1e5)];
int n;

int main(){
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cin>>n;
  for(int i=0;i<n-1;i++){
    std::cin>>eu[i]>>ev[i];
    --eu[i],--ev[i];
    adj[eu[i]] += i;
    adj[ev[i]] += i;
  }
  for(int i=0;i<n-1;i++){
    if(adj[i].size()<=2) continue;
    memset(ans,-1,(n-1)*sizeof(int));
    int x=3;
    for(int j=0;j<3;j++) ans[adj[i][j]] = j;
    for(int j=0;j<n-1;j++) std::cout << ((ans[j]<0)?x++:ans[j]) << "\n";
    return 0;
  }
  for(int i=0;i<n-1;i++) std::cout << i << "\n";
  return 0;
}
