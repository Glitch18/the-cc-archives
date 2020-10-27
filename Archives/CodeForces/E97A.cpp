#include<iostream>
using namespace std;

int main(){
  int T; cin >> T;
  while(T--){
    int x,y;
    cin >> x >> y;
    if(y-x >= x){
      cout << "NO" << "\n";
      continue;
    }
    else cout << "YES" << "\n";
  }
}
