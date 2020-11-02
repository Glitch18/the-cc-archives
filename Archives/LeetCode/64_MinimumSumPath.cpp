//https://leetcode.com/problems/minimum-path-sum/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int mem[rows][cols];

        mem[rows-1][cols-1] = grid[rows-1][cols-1];
        for(int i=rows-2;i>=0;i--)
            mem[i][cols-1] = grid[i][cols-1] + mem[i+1][cols-1];

        for(int j=cols-2;j>=0;j--)
            mem[rows-1][j] = grid[rows-1][j] + mem[rows-1][j+1];

        for(int i=rows-2;i>=0;i--)
            for(int j=cols-2;j>=0;j--)
                mem[i][j] = grid[i][j] + min(mem[i+1][j],mem[i][j+1]);

        return mem[0][0];
    }
};
