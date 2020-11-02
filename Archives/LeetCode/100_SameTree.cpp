//https://leetcode.com/problems/same-tree/

//The given solutions were recursive and iterative
class Solution {
public:
    string getLevelOrderRep(TreeNode* head){
        string ans = "";
        queue<TreeNode*> q;
        q.push(head);

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr==NULL){
                ans += "N";
                continue;
            }
            ans += curr->val;
            if(curr->left) q.push(curr->left);
            else q.push(NULL);

            if(curr->right) q.push(curr->right);
            else q.push(NULL);
        }
        return ans;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        string t1 = getLevelOrderRep(p);
        string t2 = getLevelOrderRep(q);

        return (t1.compare(t2)==0);
    }
};
