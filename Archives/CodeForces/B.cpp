#include<bits/stdc++.h>

int arr[int(1e5)];
int n;
std::vector<int> positive,negative,zero;

inline void change(int& x){
  x = -x-1;
}

int main(){
  std::cin >> n;
  int x;
  for(int i=0;i<n;i++){
    std::cin >> x;
    if(x>0) positive.push_back(x);
    else if(x==0) zero.push_back(x);
    else negative.push_back(x);
  }
  std::sort(positive.begin(),positive.end(),std::greater<int>());
  std::sort(negative.begin(),negative.end(),std::greater<int>());

  if(zero.size()%2!=0){
    if(negative.size()%2==0){
      if(positive.size()!=0){
        auto itr = positive.begin();
        for(int i=0;i<(positive.size()-1)/2*2+1;i++) change(*itr),itr++;
      }
      else if(negative.size()!=0){
        auto itr = negative.begin();
        if(*itr!=1) for(int i=0;i<positive.size()/2*2;i++) change(*itr),itr++;
        else{
          itr++;
          for(int i=0;i<(positive.size()-1)/2*2;i++) change(*itr),itr++;
        }
      }
      else for(auto itr=zero.begin();itr!=zero.end();itr++) change(*itr); 
      for(auto itr=zero.begin();itr!=zero.end();itr++) change(*itr);
    }
  }
}
