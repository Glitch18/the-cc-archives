//https://leetcode.com/problems/edit-distance/

//===========================Writing a solution with Bottom Up approach

class Solution {
public:
    int minDistance(string word1, string word2) {
        int dp[word2.size()+1][word1.size()+1];
        for(int i=0;i<=word2.size();i++){
            for(int j=0;j<=word1.size();j++){
                if(i==0) dp[i][j]=j;
                else if(j==0) dp[i][j]=i;
                else if(word1[j-1]==word2[i-1]) dp[i][j] = dp[i-1][j-1];
                //Above, the last characters are the same, so same as converting
                //the remaining i-1 and j-1 characters
                else dp[i][j] = 1 + min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                //The three situations above represent deletion, insertion and substitution
                //respectively
            }
        }
        return dp[word2.size()][word1.size()];
    }
};

//=========================Old Implementation

class Solution {
public:
    map<pair<int,int>,int> cost;

    int transform(int i,int j,string word2, string word1){
        //j corresponds to word1 and i corresponds to word 2
        if(cost.find({i,j})!=cost.end()) return cost[{i,j}];

        if(word1[j-1]==word2[i-1]){
            cost[{i,j}] = transform(i-1,j-1,word2,word1);
            return cost[{i,j}];
        }

        int price = min({transform(i-1,j,word2,word1),\
                        transform(i,j-1,word2,word1),\
                        transform(i-1,j-1,word2,word1)});
        cost[{i,j}] = price+1;
        return price+1;
    }

    int minDistance(string word1, string word2){
        cost[{0,0}] = 0;
        for(int i=1;i<=word1.size();i++) cost[{0,i}] = i;
        for(int i=1;i<=word2.size();i++) cost[{i,0}] = i;
        return transform(word2.size(),word1.size(),word2,word1);
    }
};

//===========================Above is slow because of the O(logN) of map
