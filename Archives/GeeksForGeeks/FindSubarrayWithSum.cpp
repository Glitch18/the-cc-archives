//https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0#
#include <iostream>
using namespace std;

int main() {
	int T; cin>>T;
	while(T--){
	    int n;int sum;
	    cin >> n >> sum;
	    int arr[n];
	    for(int i=0;i<n;i++) cin >> arr[i];
	    int i=0,j=0;
	    int scan = arr[0];
	    bool ans=false;
	    while(i<n || j<n){
	        if(scan==sum){
	            cout << i+1 << " " << j+1 << "\n";
	            ans=true;
	            break;
	        }
	        else if(scan<sum && j+1<n) scan += arr[++j];
	        else if(scan>sum && i+1<n) scan -= arr[i++];
	        else break;
	    }
	    if(!ans) cout << -1 << "\n";
	}
	return 0;
}

// The following also handles negative numbers:-

int fakeMain(){
  int n,sum;
  cin >> n >> sum;
  int arr[n];
  for(int i=0;i<n;i++) cin >> arr[i];

  unordered_map<int,int> store;
  int i=1,x=arr[0];
  store[arr[0]]=0;
  bool found=false;

  while(i!=n){
    x += arr[i];
    if(x==sum){
      cout << 0 << " " << i << "\n";
      found=true;
      break;
    }
    if(store.find(x-sum) != store.end()){
      cout << store[x-sum] << " " << i << "\n";
      found=true;
      break;
    }
    store[x] = i++;
  }
}
