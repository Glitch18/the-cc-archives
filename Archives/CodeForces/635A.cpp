#include<bits/stdc++.h>
#include<iostream>

//Here you can eliminate the need to store level[] of each node
//rather start dfs as dfs(node,father,int d=0) (you only need to call dfs(1,1))
//and then keep on increasing d as dfs is called for children
//store only the rewards for each node(level-subtree) using the available d per call of dfs

int n,k,x,y;
long long ans=0;
//std::vector<int> children[int(2e5)];
std::basic_string<int> children[int(2e5)];
std::priority_queue<int> score;
int level[int(2e5)] = {0};
int subtree[int(2e5)] = {0};

void dfs(int node,int father){
  level[node] = node==0 ? 0 : level[father] + 1;
  if(children[node].size()==1 && node!=0) return;
  for(auto i : children[node]) if(i!=father) dfs(i, node);
  subtree[node] = children[node].size()-1;
  for(auto i : children[node]) if(i!=father) subtree[node]+=subtree[i];
  return;
}

int main(){
  std::cin >> n >> k;
  level[0] = -1;
  for(int i=0;i<n-1;i++){
    std::cin >> x >> y;
    children[--x] += --y;
    children[y] += x;
  }
  dfs(0,-1);
  for(int i=0;i<n;i++) score.push(level[i]-subtree[i]);
  while(k--) ans+=score.top(), score.pop();
  std::cout<<ans;
}
