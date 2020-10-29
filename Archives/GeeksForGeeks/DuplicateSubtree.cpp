//https://www.geeksforgeeks.org/check-binary-tree-contains-duplicate-subtrees-size-2/
#include<string>
#include<iostream>
using namespace std;

const char MARKER = "$";
unordered_set<string> memory;

string dupSub(Node* root){
  string s = "";

  if(root==NULL) return s + MARKER;

  string lStr = dupSub(root->left);
  if(lStr.compare(s)==0) return s;

  string rStr = dupSub(root->right);
  if(rStr.compare(s)==0) return s;

  s = s + root->key + lStr + rStr;

  if(s.length()>3 && memory.find(s)!=memory.end()) return "";

  memory.insert(s);
  return s;
}
