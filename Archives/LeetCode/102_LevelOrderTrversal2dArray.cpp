//https://leetcode.com/problems/binary-tree-level-order-traversal/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;

        vector<int> curr;

        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            TreeNode* p = q.front();
            q.pop();
            if(p!=NULL){
                curr.push_back(p->val);
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
            else{
                ans.push_back(curr);
                curr.clear();
                if(!q.empty()) q.push(NULL);
            }
        }

        return ans;
    }
};
