//https://leetcode.com/problems/combination-sum-ii/

class Solution {
public:
    void findSum(const vector<int>& candidates, int index, int target, vector<vector<int>>& ans, vector<int> current){
        if(target==0){
            ans.push_back(current);
            return;
        }

        if(target<0) return;

        for(int i=index;i<candidates.size();i++){
            if(i==index || candidates[i]!=candidates[i-1]){
                current.push_back(candidates[i]);
                findSum(candidates,i+1,target-candidates[i],ans,current);
                current.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        findSum(candidates,0,target,ans,{});
        return ans;
    }
};
