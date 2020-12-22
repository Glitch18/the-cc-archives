#include<bits/stdc++.h>
#include<iostream>

//Maths; Binary Search

unsigned long long int findOptimum(std::vector<unsigned long long int>& first,std::vector<unsigned long long int>& second,std::vector<unsigned long long int>& third){
  unsigned long long int min = ULLONG_MAX;
  for(auto j : second){
    auto i = std::upper_bound(first.begin(),first.end(),j);
    if(i==first.begin()) continue;
    i--;
    auto k = std::lower_bound(third.begin(),third.end(),j);
    if(k==third.end()) continue;
    unsigned long long int value = (j-*i)*(j-*i)+(*k-j)*(*k-j)+(*k-*i)*(*k-*i);
    if(value<min) min = value;
  }
  return min;
}

int main(){
  int t,nr,ng,nb,input;
  std::cin >> t;
  std::vector<unsigned long long int> red,green,blue;
  std::set<unsigned long long int> solutions;
  while(t--){
    std::cin >> nr >> ng >> nb;
    while(nr--) std::cin >> input , red.push_back(input);
    while(ng--) std::cin >> input , green.push_back(input);
    while(nb--) std::cin >> input , blue.push_back(input);

    std::sort(red.begin(),red.end());
    std::sort(green.begin(),green.end());
    std::sort(blue.begin(),blue.end());

    solutions.insert(findOptimum(red,green,blue));
    solutions.insert(findOptimum(blue,green,red));
    solutions.insert(findOptimum(green,red,blue));
    solutions.insert(findOptimum(blue,red,green));
    solutions.insert(findOptimum(red,blue,green));
    solutions.insert(findOptimum(green,blue,red));

    std::cout << *solutions.begin() << "\n";
    solutions.clear();
    red.clear();
    green.clear();
    blue.clear();
  }
}
