#include<iostream>
#include<stack>
using namespace std;

struct Node{
  int data;
  Node* left,*right;
  Node(int x){
    data=x;
    left=NULL;
    right=NULL;
  }
};

void Inorder(Node* root){
  if(!root) return;

  stack<Node*> st;
  st.push(root);
  Node* curr = root->left;

  while(curr!=NULL || !st.empty()){
    if(curr==NULL){
      curr = st.top(); st.pop();
      cout << curr->data << " ";
      curr = curr->right;
      continue;
    }
    st.push(curr);
    curr = curr->left;
  }
}

int main(){
  /* Constructed binary tree is
              1
            /   \
          2      3
        /  \
      4     5
  */
  Node *root = new Node(1);
  root->left        = new Node(2);
  root->right       = new Node(3);
  root->left->left  = new Node(4);
  root->left->right = new Node(5);

  Inorder(root);
  return 0;
}
