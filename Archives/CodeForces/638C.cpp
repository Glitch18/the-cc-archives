#include<bits/stdc++.h>

int t,n,k;
std::vector<char> string(int(1e5));

int main(){
  for(std::cin>>t;t;t--){
    std::cin>>n>>k;
    for(int i=0;i<n;i++) std::cin>>string[i];
    std::sort(string.begin(),string.begin()+n);
    std::vector<char> copy(string.begin(),string.begin()+k);
    string.erase(string.begin(),string.begin()+k);

    if(*copy.begin()!=*(copy.begin()+k-1) || n==k){
      std::cout << *(copy.begin()+k-1) << "\n";
      continue;
    }

    else if(*string.begin()!=*(string.begin()+n-k-1)){
      std::cout << *copy.begin();
      for(auto itr = string.begin(); itr<string.begin()+n-k;itr++) std::cout << *itr;
      std::cout << "\n";
      continue;
    }

    std::cout << *copy.begin();
    int i = (n-k)/k + ((n-k)%k!=0);
    if(n-k<=k) i = 1;
    while(i--) std::cout << *string.begin();
    std::cout << "\n";
    continue;
  }
}
