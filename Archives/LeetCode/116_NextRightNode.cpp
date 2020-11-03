//https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return NULL;
        queue<Node*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            if(curr){
                curr->next = q.front();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            else if(!q.empty()) q.push(NULL);
        }
        return root;
    }
};
