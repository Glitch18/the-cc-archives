//https://leetcode.com/problems/word-ladder-ii/

class Solution {
    unordered_map<string,int> level; //also used as visited
    unordered_map<string,vector<string>> adj;
    string end;
    int depth;
public:
    void dfs(vector<vector<string>> &ans,string word,vector<string> curr){
        curr.push_back(word);
        int lvl = curr.size(); //current level in the dfs call

        if(word==end){
            ans.push_back(curr);
            return;
        }

        for(int i=0;i<word.size();i++){
            string temp = word;
            temp[i] = '*';
            for(auto j:adj[temp]){
                if(level[j]==lvl+1)
                    dfs(ans,j,curr);
            }
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        if(wordList.size()==0) return {};

        for(auto i:wordList){
            for(int j=0;j<i.size();j++){
                string temp = i;
                temp[j]='*';
                adj[temp].push_back(i);
            }
        }

        end = endWord;
        queue<pair<string,int>> que;
        que.push({beginWord,1});

        while(!que.empty()){
            string curr = que.front().first;
            int lvl = que.front().second;
            que.pop();
            if(level.find(curr)!=level.end()) continue; //already visited

            level[curr] = lvl; //store level for this node. vis = 1;

            for(int i=0;i<curr.size();i++){
                string temp = curr;
                temp[i]='*';
                for(auto j:adj[temp]){
                    if(level.find(j)==level.end())
                        que.push({j,lvl+1});
                }
            }
        }

        depth = level[endWord];

        vector<vector<string>> ans;

        for(int i=0;i<beginWord.size();i++){
            string temp = beginWord;
            temp[i]='*';
            for(auto j:adj[temp]){
                dfs(ans,j,{beginWord});
            }
        }

        return ans;
    }
};
