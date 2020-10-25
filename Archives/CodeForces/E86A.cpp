#include<iostream>
#include<limits.h>
using namespace std;

short int t;
long long int x,y,a,b;

int main(){
  for(cin >> t;t;t--){
    long long int ans=LLONG_MAX;
    cin >> x >> y >> a >> b;
    int total = x+y;
    int small = (x<y)?x:y;
    cout << min(small*b + (total-2*small)*a,total*a) << "\n";
  }
}
