//https://www.geeksforgeeks.org/next-greater-element/
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm> //reverse
using namespace std;

vector<int> array,ans;
stack<int> greatest;

int findNGE(int x){
  if(greatest.empty()){
    greatest.push(array[x]);
    return -1;
  }
  while(greatest.top()<=array[x]){
    greatest.pop();
    if(greatest.empty()) break;
  }
  int ans = (greatest.empty()) ? -1 : greatest.top();
  greatest.push(array[x]);
  return ans;
}

int main(){
  int n;
  cin >> n;
  for(int i=0;i<n;i++){
    int x; cin >> x;
    array.push_back(x);
  }
  for(int i=n-1;i>=0;i--){
    //i is the index of element in the array
    //that we're trying to find the NGE of
    ans.push_back(findNGE(i));
  }
  reverse(ans.begin(),ans.end());
  for(auto i : ans) cout << i << " ";
  return 0;
}
