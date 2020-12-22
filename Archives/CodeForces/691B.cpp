//https://codeforces.com/problemset/problem/1459/B
#include<iostream>
using namespace std;

int main(){
  int x; cin >> x;
  int y = (x%2==0) ? (x/2+1)*(x/2+1) : 2*(x/2+1)*(x/2+2);
  cout << y;
}
