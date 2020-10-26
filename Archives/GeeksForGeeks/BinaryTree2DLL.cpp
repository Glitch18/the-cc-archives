pair<Node*,Node*> inorder(Node* root,Node* parent,bool isLeft){
    if(root==NULL) return {parent,parent};
    if(root->left==NULL && root->right==NULL){
        root->left = (isLeft) ? NULL : parent;
        root->right = (isLeft) ? parent : NULL;
        return {root,root};
    }

    pair<Node*, Node*> left, right;
    left = inorder(root->left,root,true);
    right = inorder(root->right,root,false);
    Node* ll = left.first;
    Node* rr = right.second;
    Node* rl = left.second;
    Node* lr = right.first;

    root->left = (rl==root)?NULL:rl;
    if(root->left != NULL) root->left->right = root;
    root->right = (lr==root)?NULL:lr;
    if(root->right != NULL) root->right->left = root;
    return {ll,rr};
}

Node * bToDLL(Node *root)
{
    Node* head = inorder(root,NULL,true).first;
    return head;
}
