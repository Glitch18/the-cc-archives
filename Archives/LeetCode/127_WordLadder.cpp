//https://leetcode.com/problems/word-ladder/

//Graph search using BFS
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,vector<string>> adj;
        unordered_map<string,int> vis;

        for(auto i:wordList) vis[i]=0;

        for(int i=0;i<wordList.size();i++){
            for(int j=0;j<wordList[i].size();j++){
                string temp = wordList[i];
                temp[j] = '*';
                adj[temp].push_back(wordList[i]);
            }
        }

        //adj list created;
        int ans = 0;
        queue<pair<string,int>> que;
        que.push({beginWord,1});

        while(!que.empty()){
            string word = que.front().first;
            int level = que.front().second;
            que.pop();
            if(word==endWord){
                ans = level;
                break;
            }

            if(vis[word]==1) continue;
            vis[word] = 1;

            for(int i=0;i<word.size();i++){
                string temp = word;
                temp[i] = '*';
                for(auto j:adj[temp]){
                    if(vis[j]==1) continue;
                    else que.push({j,level+1});
                }
            }
        }
        return ans;
    }
};
