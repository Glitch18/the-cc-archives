#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main(){
  vector<vector<int>> A = {{1, 1, 1},
                           {2, 2, 2},
                           {3, 8, 6}};
  int N = A.size();
  int B = 2;

  vector<vector<int>> res(N+1, vector<int>(N+1, 0));
  for(int i = 0; i < N; i++) {
    for(int j = 1; j < N; j++) {
      A[i][j] = A[i][j] + A[i][j-1];
    }
  }

  for(int i = 0; i < N; i++) {
    for(int j = 1; j < N; j++) {
      A[j][i] = A[j][i] + A[j-1][i];
    }
  }

  for(int i=0; i<A.size(); i++){
    for(int j=0; j<A[0].size(); j++){
      cout << A[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "\n";

  for(int i = 0 ; i < N; i++) {
    for(int j = 0; j < N; j++) {
      res[i+1][j+1] += A[i][j];
    }
  }

  int max_sum = INT_MIN;

  for(int i = B; i < N+1; i++) {
    for(int j = B; j < N+1; j++) {
      int sum = res[i-B][j] - res[i-B][j-B];
      if(i==3 && j==3) cout << sum << " ";

      sum += res[i][j-B] - res[i-B][j-B];
      if(i==3 && j==3) cout << sum << " ";

      sum += res[i-B][j-B];
      if(i==3 && j==3) cout << sum << " ";
      max_sum = max(max_sum,res[i][j] - sum);
    }
  }
  cout << "\n";
  cout << max_sum;
}
