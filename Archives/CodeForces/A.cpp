#include<iostream>
using namespace std;

int main(){
  int a;
  cin >> a;
  long long int ans = 1 + 4*(a*(a-1)/2);
  cout << ans;
}
