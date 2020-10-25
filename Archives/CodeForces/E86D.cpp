#include<bits/stdc++.h>

int n,k,x;
int m[int(2e5)] = {0};
int size[int(2e5)];
int c[int(2e5)+1];

int main(){
  std::cin >> n >> k;
  for(int i=0;i<n;i++) std::cin >> size[i], m[size[i]]++;
  for(int i=1;i<=k;i++) std::cin>>c[i];
  int max=0,freq=0;
  std::sort(size,size+n,std::greater<int>());
  for(int i=k;i>=1;i--) freq += m[i],max = std::max(max,freq/c[i]+(freq%c[i]>0));
  std::cout<<max<<"\n";

  for(int i=0; i<max; i++){
		std::cout << n / max + (i < n % max);
		for(int j=i; j<n; j+=max)
			std::cout << " " << size[j];
		std::cout << "\n";
	}
}
