#include<iostream>
#include<unordered_map>
using namespace std;

unordered_map<int,long long> factorial;

long long fact(int x){
    if(factorial.find(x)!=factorial.end()){
        return factorial[x];
    }
    return x*fact(x-1);
}

long long numSets(int n){
    //return nCr/2 where r is n/2
    long long ncr = fact(n);
    ncr /= fact(n/2)*fact(n/2);
    return ncr/2;
}

int main(){
    factorial[0] = 1;
    int n;
    cin >> n;
    long long ans = numSets(n);
    ans *= fact(n/2-1)*fact(n/2-1);
    cout << ans;
}
