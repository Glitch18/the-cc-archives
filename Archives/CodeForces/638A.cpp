#include<iostream>
#include<cmath>
using namespace std;

int main(){
  int t,n;
  cin >> t;
  while(t--){
    cin >> n;
    long long int a = pow(2,(n/2)+1) - 2;
    cout << a << "\n";
  }
}
