//https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
class Solution {
public:
    TreeNode* makeBinTree(vector<int> nums,int left,int right){
        if(left>right) return NULL;
        int midpoint = left + (right-left)/2;
        TreeNode* thisRoot = new TreeNode(nums[midpoint]);
        thisRoot->left = makeBinTree(nums,left,midpoint-1);
        thisRoot->right = makeBinTree(nums,midpoint+1,right);
        return thisRoot;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0) return NULL;
        return makeBinTree(nums,0,nums.size()-1);
    }
};
