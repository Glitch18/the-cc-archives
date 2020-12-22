#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

string chars = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";

int main(){
  int N;
  cin >> N;
  while(N--){
    int x;
    cin >> x;
    vector<int> a = {0};
    for(int i=0;i<x;i++){
      int temp; cin >> temp;
      a.push_back(temp);
    }

    cout << chars << "\n";

    for(int i=1;i<=x;i++){
      chars[a[i]]++;
      if(chars[a[i]]>122) chars[a[i]]-=26;
      cout << chars << "\n";
    }
    a.clear();
    chars = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
  }
}
