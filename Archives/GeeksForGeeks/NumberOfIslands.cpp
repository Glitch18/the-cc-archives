//https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1
#include<iostream>
#include<vector>
#include<utility>
using namespace std;

void erase(vector<int>* A,pair<int,int> self,vector<int>* vis,int N,int M){
    //i goes along the row
    //j goes along the columns
    //[j][i]
		vis[self.first][self.second]=1;
		vector<pair<int,int>> around;

    for(int j=self.first-1;j<=self.first+1;j++)
        for(int i=self.second-1;i<=self.second+1;i++)
            if(j>=0 && j<N && i>=0 && i<M)
								around.push_back({j,i});

		for(auto i:around)
			if(vis[i.first][i.second]==0 && A[i.first][i.second])
				erase(A,i,vis,N,M);

    A[self.first][self.second]=0;
    return;
}

int findIslands(vector<int>* A, int N, int M) {
		vector<int> visited[N];
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
				visited[i].push_back(0);

    int count=0;
    for(int j=0;j<N;j++)
        for(int i=0;i<M;i++){
            if(A[j][i]==1){
							count++;
							//cout << "Calling " << j << i << "\n";
							erase(A,{j,i},visited,N,M);
						}
        }
		return count;
}

int main(){
	vector<int> A[3];
	A[0].push_back(1);
	A[0].push_back(1);
	A[0].push_back(0);
	A[1].push_back(0);
	A[1].push_back(0);
	A[1].push_back(1);
	A[2].push_back(1);
	A[2].push_back(0);
	A[2].push_back(1);

	cout << findIslands(A,3,3);
}
