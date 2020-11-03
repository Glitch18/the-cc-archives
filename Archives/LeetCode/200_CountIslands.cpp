//https://leetcode.com/problems/number-of-islands/
class Solution {
public:
    void eraseIsland(vector<vector<char>> &grid,vector<vector<int>> &vis,int i,int j){
        vector<pair<int,int>> around;

        vis[i][j] = 1;

        if(i-1 >= 0) around.push_back({i-1,j});
        if(i+1 < grid.size()) around.push_back({i+1,j});
        if(j-1 >= 0) around.push_back({i,j-1});
        if(j+1 < grid[0].size()) around.push_back({i,j+1});

        for(auto a : around){
            if(vis[a.first][a.second]==0 && grid[a.first][a.second]=='1')
                eraseIsland(grid,vis,a.first,a.second);
        }
        grid[i][j] = '0';
    }

    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0) return 0;
        vector<vector<int>> vis(grid.size());

        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
                vis[i].push_back(0);

        int count = 0;

        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    count++;
                    eraseIsland(grid,vis,i,j);
                }
            }
        return count;
    }
};
