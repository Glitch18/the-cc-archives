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

node *getNextRight(node *p)
{
    node *temp = p->nextRight;

    /* Traverse nodes at p's level
    and find and return the first
    node's first child */
    while (temp != NULL)
    {
        if (temp->left != NULL)
            return temp->left;
        if (temp->right != NULL)
            return temp->right;
        temp = temp->nextRight;
    }

    // If all the nodes at p's level
    // are leaf nodes then return NULL
    return NULL;
}

void connectRecur(node* p)
{
    node *temp;

    if (!p)
    return;

    // Set nextRight for root
    p->nextRight = NULL;

    // set nextRight of all levels one by one
    while (p != NULL)
    {
        node *q = p;

        /* Connect all childrem nodes of p and
        children nodes of all other nodes at
        same level as p */
        while (q != NULL)
        {
            // Set the nextRight pointer
            // for p's left child
            if (q->left)
            {
                // If q has right child, then
                // right child is nextRight of
                // p and we also need to set
                // nextRight of right child
                if (q->right)
                    q->left->nextRight = q->right;
                else
                    q->left->nextRight = getNextRight(q);
            }

            if (q->right)
                q->right->nextRight = getNextRight(q);

            // Set nextRight for other
            // nodes in pre order fashion
            q = q->nextRight;
        }

        // start from the first
        // node of next level
        if (p->left)
            p = p->left;
        else if (p->right)
            p = p->right;
        else
            p = getNextRight(p);
    }
}  
