//https://practice.geeksforgeeks.org/problems/check-for-bst/1
bool checkNode(Node* curr,int* check){
    if(!curr) return true;
    if(!checkNode(curr->left,check)) return false;
    if(curr->data <= *check) return false;
    *check = curr->data;
    if(!checkNode(curr->right,check)) return false;
    return true;
}

bool isBST(Node* root) {
    int* check = new int;
    *check = -1;
    return checkNode(root,check);
}
