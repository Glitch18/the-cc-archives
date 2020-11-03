//https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size()==NULL) return NULL;

        stack<TreeNode*> st;

        TreeNode* root = new TreeNode(preorder[0]);
        st.push(root);
        TreeNode* lastNode = root;

        for(int i=1;i<preorder.size();i++){
            while(st.top()->val<preorder[i]){
                lastNode = st.top();
                st.pop();
                if(st.empty()) break;
            }

            TreeNode* newNode = new TreeNode(preorder[i]);
            if(lastNode->val>preorder[i]) lastNode->left = newNode;
            else lastNode->right = newNode;
            st.push(newNode);
            lastNode = newNode;
        }

        return root;
    }
};
