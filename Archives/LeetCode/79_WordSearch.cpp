//https://leetcode.com/problems/word-search/
class Solution {
public:
    bool checkNext(vector<int>* vis, const vector<vector<char>> &board,\
               string word,int i,int j){
        vis[i][j] = 1;
        if(board[i][j]==word[0]){
            if(word.size()==1) return true;
            vector<pair<int,int>> around;
            if(i-1>=0) around.push_back({i-1,j});
            if(i+1<board.size()) around.push_back({i+1,j});
            if(j-1>=0) around.push_back({i,j-1});
            if(j+1 < board[0].size()) around.push_back({i,j+1});
            for(auto i:around){
                if(vis[i.first][i.second]==0){
                    if(checkNext(vis,board,word.substr(1),i.first,i.second)){
                        return true;
                    }
                }
            }
        }
        vis[i][j] = 0;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        vector<int> vis[rows];

        for(int i=0;i<rows;i++)
            for(int j=0;j<cols;j++)
                vis[i].push_back(0);

        for(int i=0;i<rows;i++)
            for(int j=0;j<cols;j++)
                if(checkNext(vis,board,word,i,j))
                    return true;

        return false;
    }
};
