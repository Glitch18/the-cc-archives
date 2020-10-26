#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<long long> arr,stack;

void solve(){
    unordered_map<long long,long long> ans;

    stack.push_back(arr[0]);
    for(int i=1;i<arr.size();i++){
        if(stack.back()<arr[i]){
            ans[stack.back()] = arr[i];
            stack.pop_back();
            if(!stack.empty()) while(stack.back()<arr[i]){
                ans[stack.back()] = arr[i];
                stack.pop_back();
                if(stack.empty()) break;
            }
            stack.push_back(arr[i]);
        }
        else stack.push_back(arr[i]);
    }
    while(!stack.empty()){
        ans[stack.back()] = -1;
        stack.pop_back();
    }
    for(auto i:arr) cout << ans[i] << " ";
    cout << "\n";
}

int main() {
	int T;
	cin >> T;
	while(T--){
	    int x; cin >> x;
	    for(int i=0;i<x;i++){
	        long long temp; cin >> temp;
	        arr.push_back(temp);
	    }
	    solve();
	    arr.clear();
	    stack.clear();
	}
	return 0;
}
