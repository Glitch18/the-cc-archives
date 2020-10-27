//https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0
#include <iostream>
using namespace std;

void solve(){
    int N,K; cin >> N >> K;
    int arr[N];
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }

    int max=0,maxIndex;
    for(int i=0;i<K;i++) if(arr[i]>max){
        max = arr[i];
        maxIndex = i;
    }
    cout << max << " ";

    for(int i=K;i<N;i++){
        if(arr[i]>=max){
            max=arr[i];
            maxIndex=i;
            cout << max << " ";
            continue;
        }

        else if(maxIndex<(i-K+1)){
            max=0;
            for(int j=0;j<K;j++){
                if(arr[i-K+1+j]>max){
                    max = arr[i-K+1+j];
                    maxIndex = i-K+1+j;
                }
            }
            cout << max << " ";
            continue;
        }

        else cout << max << " ";
    }
    cout << "\n";
}

int main() {
	int T; cin >> T;
	while(T--){
	    solve();
	}
	return 0;
}
