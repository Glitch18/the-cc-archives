//https://leetcode.com/problems/permutations/

class Solution {
public:
    void addPermutations(vector<int> nums,vector<vector<int>> &ans,vector<int> curr){
        if(nums.size()==0){
            ans.push_back(curr);
            return;
        }

        for(int i=0;i<nums.size();i++){
            curr.push_back(nums[i]);
            vector<int> newNums = nums;
            newNums.erase(newNums.begin()+i);
            addPermutations(newNums,ans,curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        addPermutations(nums,ans,{});
        return ans;
    }
};
