#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<map>
#include<queue>
#include<utility>
using namespace std;

struct Node{
  int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

unordered_map<int,vector<int>> levels;

void visitNode(int score,Node* curr){
    if(curr==NULL) return;
    visitNode(score+1,curr->right);
    visitNode(score-1,curr->left);
    levels[score].push_back(curr->data);
    return;
}

// root: root node of the tree
vector<int> verticalOrder(Node *root)
{
    visitNode(0,root);
    vector<int> keys,ans;
    for(auto kv:levels) keys.push_back(kv.first);
    sort(keys.begin(),keys.end());
    for(auto i:keys){
        for(auto ritr=levels[i].rbegin();ritr!=levels[i].rend();ritr++){
            ans.push_back(*ritr);
        }
    }
    levels.clear();
    return ans;
}

//==============Above code didn't work because nodes on the same
//vertical line are not printed in level verticalOrder
//Study following code for level order

vector<int> getVerticalOrder(Node* root){
  if(!root) return {};

  map<int,vector<int>> m;
  queue<pair<Node*,int>> q;
  vector<int> ans;
  q.push({root,0});

  while(!q.empty()){
    pair<Node*,int> temp = q.front();
    q.pop();
    Node* curr = temp.first;
    int hd = temp.second;
    m[hd].push_back(curr->data);

    if(curr->left!=NULL) q.push({curr->left,hd-1});
    if(curr->right!=NULL) q.push({curr->right,hd+1});
  }

  for(auto i:m){
    for(auto j:i.second) ans.push_back(j);
  }
  return ans;
}

int main(){
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);
  root->right->left->right = new Node(8);
  root->right->right->right = new Node(9);
  root->right->right->left = new Node(10);
  root->right->right->left->right = new Node(11);
  root->right->right->left->right->right = new Node(12);
  vector<int> ans = getVerticalOrder(root);
  for(auto i:ans) cout << i << " ";
  return 0;
}
