#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> a;
set<int> s;
bool done=0;

void solve(){
  int n,size;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> size;
    a.push_back(size);
    s.insert(a[i]);
  }
  int ans=-1;
  if(s.size()==1){
    cout << ans << "\n";
    a.clear();s.clear();
    done=0;
    return;
  }

  int max = *max_element(a.begin(),a.end());
  vector<int>::iterator itr = find(a.begin(),a.end(),max);

  while(itr!=a.end()&&!done){
    if(itr!=a.begin()){
      if(*prev(itr)<max){
        done=1;
        ans=itr-a.begin();
      }
    }
    if(itr!=prev(a.end())){
      if(*next(itr)<max){
        done=1;
        ans=itr-a.begin();
      }
    }
    itr = find(next(itr),a.end(),max);
  }
  a.clear();s.clear();
  done=0;
  cout << ans+1 << "\n";
}

int main(){
  int t;
  cin >> t;
  while(t--) solve();
  return 0;
}
