#include<vector>
#include<iostream>
#include<algorithm>
int main(){
  std::vector<int> v = {2,4,1,5,2,7,9,2,3,4,5};
  for(auto i : v) std::cout << i << " ";
  std::cout << "\n";
  auto itr = std::max_element(v.begin(),v.begin()+11);
  int index = itr-v.begin();
  v.erase(itr);
  for(auto i : v) std::cout << i << " ";
  std::cout << "\n";
  std::cout << v[index];
}
