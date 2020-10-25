#include<bits/stdc++.h>

long long int a,b,t,k;
long long int l,r;

long long int count(long long int const r, long long int lcm, long long int b){
  long long int blocks = r/lcm;
  long long int last = blocks * lcm;
  long long int ans = r;
  if(blocks != 0){
    ans -= std::min(b,r-last+1);
    ans -= b*(blocks-1);
  }
  return ans - std::min(b-1,r);
}

int main(){
  for(std::cin>>t;t;t--){
    std::cin >> a >> b >> k;
    if(a>b) std::swap(a,b);
    long long int lcm = (a*b)/std::__gcd(a,b);
    while(k--){
      std::cin >> l >> r;
      if(lcm == b || r<b){
        std::cout << 0 << " ";
        continue;
      }
      long long int ans = count(r,lcm,b);
      if(l>1) ans -= count(l-1,lcm,b);
      std::cout << ans << " ";
    }
    std::cout << "\n";
  }
}
