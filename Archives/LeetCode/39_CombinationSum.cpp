//https://leetcode.com/problems/combination-sum/

class Solution {
public:
    void findSum(const vector<int> &candidates, int index, int target,vector<vector<int>> &ans,vector<int> current){
        if(target==0){
            ans.push_back(current);
            return;
        }
        if(target<0) return;

        for(int i=index;i<candidates.size();i++){
            int repetitions = target/candidates[i];
            for(int j=1;j<=repetitions;j++){
                current.push_back(candidates[i]);
                findSum(candidates,i+1,target-candidates[i]*j,ans,current);
            }
            for(int j=0;j<repetitions;j++) current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<int> sorted(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        candidates.clear();
        for(auto i : sorted) candidates.push_back(i);

        findSum(candidates, 0, target,ans,{});
        return ans;
    }
};
