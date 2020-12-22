#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<vector>
#include<utility>
using namespace std;

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){
  return (a.second > b.second);
}

int main(){
  int n;
  scanf("%d",&n);
  std::vector<pair<int,int>> first,second;
  while(n--){
    int x,y;
    scanf("%d %d",&x,&y);
    first.push_back(make_pair(x,y));
  }
  second = first;
  sort(first.begin(),first.end());
  sort(second.begin(),second.end(),sortbysec);

  /*for(auto i:first) printf("%d-%d ",i.first,i.second);
  printf("\n");
  for(auto i:second) printf("%d-%d ",i.first,i.second);
  */
  if(binary_search(first.begin(),first.end(),make_pair(first[0].first,second[0].second))) return printf("YES\n");
  else return printf("NO");
}
