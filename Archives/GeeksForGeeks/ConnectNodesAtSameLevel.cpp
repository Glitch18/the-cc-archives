//https://practice.geeksforgeeks.org/problems/connect-nodes-at-same-level/1#

/* struct Node
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
}; */

// Should set the nextRight for all nodes
void connect(Node *p)
{
   queue<Node*> que;
   que.push(p);
   que.push(NULL);

   while(!que.empty()){
       Node* curr = que.front();
       que.pop();
       if(curr!=NULL){
           curr->nextRight = que.front();
           if(curr->left) que.push(curr->left);
           if(curr->right) que.push(curr->right);
       }
       else if(!que.empty()){
           que.push(NULL);
       }
   }
}

//Also see: https://www.geeksforgeeks.org/connect-nodes-at-same-level-with-o1-extra-space/
