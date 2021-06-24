//https://leetcode.com/problems/partition-labels/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int lastOcc[256];
        for(int i=0; i<s.size(); i++){
            lastOcc[s[i]] = i;
        }

        vector<int> ans;
        int curr = -1;
        int prev = 0;
        for(int i=0;i<s.size();i++){
            if(lastOcc[s[i]] > curr) curr = lastOcc[s[i]];
            if(i==curr){
                ans.push_back(curr-prev+1);
                prev = curr+1;
            }
        }
        return ans;
    }
};
