//https://leetcode.com/problems/valid-sudoku/

//Naive solution - iterate over the board three times.
class Solution {
public:
    bool checkBox(vector<vector<char>> const &board,int a,int b){
        // i is the top left corner of given square
        int M = board.size()/3;

        unordered_set<char> prev;

        for(int i=a;i<a+M;i++){
            for(int j=b;j<b+M;j++){
                if(board[i][j]=='.') continue;
                if(prev.find(board[i][j])!=prev.end()) return false;
                else prev.insert(board[i][j]);
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        string valid = "123456789";
        unordered_set<char> prev;
        //checking rows:-
        for(int a=0;a<board.size();a++){
            for(auto i : board[a]){
                if(i=='.') continue;
                if(prev.find(i)!=prev.end()) return false;
                if(valid.find(i)==string::npos) return false;
                else prev.insert(i);
            }
            prev.clear();
        }
        //checking columns
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board.size();j++){
                //column element [j][i]
                if(board[j][i]=='.') continue;
                if(prev.find(board[j][i])!=prev.end()) return false;
                if(valid.find(board[j][i])==string::npos) return false;
                else prev.insert(board[j][i]);
            }
            prev.clear();
        }
        //check boes
        for(int i=0;i<board.size();i+=3){
            for(int j=0;j<board.size();j+=3){
                if(!checkBox(board,i,j)) return false;
            }
        }
        return true;
    }
};

//Efficient solution - single pass through the board

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,unordered_set<char>> rows;
        unordered_map<int,unordered_set<char>> col;
        unordered_map<int,unordered_set<char>> box;

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board.size();j++){
                if(board[i][j]=='.') continue;
                if(rows[i].find(board[i][j])!=rows[i].end()) return false;
                if(col[j].find(board[i][j])!=col[j].end()) return false;
                int box_index = (i/3)*3 + j/3;
                if(box[box_index].find(board[i][j])!=box[box_index].end())
                    return false;

                rows[i].insert(board[i][j]);
                col[j].insert(board[i][j]);
                box[box_index].insert(board[i][j]);
            }
        }
        return true;
    }
};
