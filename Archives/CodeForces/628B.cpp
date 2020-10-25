#include<iostream>
#include<set>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int x;
		cin >> x;
		int arr[x];
		for(int i=0;i<x;i++) cin >> arr[i];
		set<int> s;
		for(auto i : arr) s.insert(i);
		cout << s.size() << endl;
	}
}
