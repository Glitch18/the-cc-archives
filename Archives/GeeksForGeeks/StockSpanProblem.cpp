//https://practice.geeksforgeeks.org/problems/stock-span-problem/0#
#include <iostream>
#include <vector>
using namespace std;

void solve(){
    vector<int> v;

    int N; cin >> N;
    for(int i=0;i<N;i++){
        int temp; cin>>temp;
        v.push_back(temp);
    }

    int prev[N]; prev[0] = 1;

    for(int i=1;i<N;i++){
        int span = 1;
        int index = i-1;
        if(index>=0) while(v[index]<=v[i]){
            span += prev[index];
            index -= prev[index];
            if(index<0) break;
        }
        prev[i]=span;
    }

    for(int i=0;i<N;i++) cout << prev[i] << " ";
    cout << "\n";
}

int main() {
	int T;
	cin >> T;
	while(T--){
	    solve();
	}
	return 0;
}
