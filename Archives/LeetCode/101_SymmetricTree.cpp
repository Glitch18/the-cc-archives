//https://leetcode.com/problems/symmetric-tree/

//recursive
class Solution {
public:
    bool compare(TreeNode* one, TreeNode* two){
        if(one==NULL && two==NULL) return true;
        if(one==NULL && two!=NULL) return false;
        if(one!=NULL && two==NULL) return false;
        if(one->val != two->val) return false;
        if(!compare(one->right,two->left)) return false;
        if(!compare(one->left,two->right)) return false;
        return true;
    }

    bool isSymmetric(TreeNode* root){
        if(root==NULL) return true;
        return compare(root->left,root->right);
    }
};

//iterative
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        queue<pair<TreeNode*,TreeNode*>> q;
        q.push({root->left,root->right});

        while(!q.empty()){
            TreeNode* one = q.front().first;
            TreeNode* two = q.front().second;

            q.pop();

            if(one==NULL && two==NULL) continue;
            if(one==NULL && two!=NULL) return false;
            if(one!=NULL && two==NULL) return false;
            if(one->val != two->val) return false;
            q.push({one->left,two->right});
            q.push({one->right,two->left});
        }
        return true;
    }
};
