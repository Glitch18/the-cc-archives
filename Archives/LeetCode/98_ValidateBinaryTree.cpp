//https://leetcode.com/problems/validate-binary-search-tree/

class Solution {
public:
    bool validSub(TreeNode* root,long long* check){
        if(root==NULL) return true;
        if(!validSub(root->left,check)) return false;
        if(root->val <= *check) return false;
        *check = root->val;
        if(!validSub(root->right,check)) return false;
        return true;
    }

    bool isValidBST(TreeNode* root) {
        long long* check = new long long;
        *check = LLONG_MIN;
        return validSub(root,check);
    }
};
