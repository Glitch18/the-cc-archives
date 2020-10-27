//https://practice.geeksforgeeks.org/problems/level-order-traversal/1

/* A binary tree Node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//You are required to complete this method
vector<int> levelOrder(Node* node){

    if(!node) return {};
    queue<Node*> q;
    vector<int> ans;
    q.push(node);

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        ans.push_back(curr->data);
        if(curr->left!=NULL) q.push(curr->left);
        if(curr->right!=NULL) q.push(curr->right);
    }
    return ans;
}
