#include<bits/stdc++.h>

std::vector<int> arr1(int(1e5));
int n,q;
long long int x;

int main(){
  std::cin>>n>>q;
  for(int i=0;i<n;i++) std::cin>>arr1[i];
  std::vector<int> arr2(arr1.begin(),arr1.begin()+n);
  std::vector<int> maxIndex(n); maxIndex[0] = 0;
  for(auto itr=arr2.begin()+1;itr<arr2.end();itr++) if(*itr < *(itr-1)) std::iter_swap(itr,itr-1);
  for(int i=1;i<n;i++) maxIndex[i] = (arr1[i] > arr1[maxIndex[i-1]]) ? i : maxIndex[i-1];

  for(q;q;q--){
    std::cin >> x;
    int index = maxIndex[std::min((long long)n,x)-1];
    std::cout << arr1[index] << " ";
    x -= index+1, x = (index+x)%(n-1);
    auto itr = (x>=index) ? arr1.begin()+x+1 : arr2.begin()+x;
    std::cout << *itr << "\n";
  }
}
