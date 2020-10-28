//https://practice.geeksforgeeks.org/problems/maximum-difference-between-node-and-its-ancestor/1#
int findMin(Node* curr,unordered_map<Node*,int> &minOf){
    if(!curr) return INT_MAX;
    if(minOf.find(curr)!=minOf.end()) return minOf[curr];
    int mini = INT_MAX;
    int left = findMin(curr->left,minOf);
    int right = findMin(curr->right,minOf);
    mini = min(left,right);
    mini = min(mini,curr->data);
    minOf[curr] = mini;
    return mini;
}

void Inorder(Node* curr,unordered_map<Node*,int> &minOf,int* ans){
    if(!curr) return;
    Inorder(curr->left,minOf,ans);
    Inorder(curr->right,minOf,ans);
    int mini = min(findMin(curr->left,minOf),findMin(curr->right,minOf));
    if((curr->data - mini) > *ans) *ans = curr->data - mini;
    return;
}

/* Your are required to
complete this method*/
int maxDiff(Node* root){
    unordered_map<Node*,int> minOf;
    if(!root) return 0;
    int* ans = new int;
    *ans = INT_MIN;
    Inorder(root,minOf,ans);
    return *ans;
}
