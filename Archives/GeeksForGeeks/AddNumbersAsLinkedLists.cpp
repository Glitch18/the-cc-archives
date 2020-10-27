//https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1#

#include<iostream>
using namespace std;

struct Node{
  int data;
  Node* next;
  Node(int x){
    data = x;
    next = NULL;
  }
};

void printList(Node* const head){
  Node* curr = head;
  while(curr!=NULL){
    cout << curr->data << " ";
    curr = curr->next;
  }
  cout << "\n";
}

struct Node* reverseList(struct Node* &head,struct Node* curr){
    if(curr->next==NULL){
        head = curr;
        return curr;
    }
    reverseList(head,curr->next)->next = curr;
    curr->next = NULL;
    return curr;
}

void insert(Node* &head,int x){
    if(head==NULL){
        head=new Node(x);
    }
    else{
        Node* curr = head;
        while(curr->next!=NULL) curr = curr->next;
        curr->next = new Node(x);
    }
}

struct Node* addTwoLists(struct Node* &origFirst, struct Node* &origSecond){
    reverseList(origFirst,origFirst);
    reverseList(origSecond,origSecond);
    Node* ans = NULL, *first=origFirst, *second=origSecond;

    bool carry = 0;

    while(first!=NULL || second!=NULL){
        int digit = 0;
        if(first){
            digit += first->data;
            first = first->next;
        }
        if(second){
            digit += second->data;
            second = second->next;
        }
        digit += carry;

        if(digit>9){
            carry = true;
            digit = digit%10;
        }
        else carry = false;

        insert(ans,digit);
    }
    if(carry) insert(ans,1);

    reverseList(ans,ans);
    return ans;
}

int main(){
  Node* first = NULL;
  insert(first,9);
  insert(first,5);
  insert(first,0);
  Node* second = NULL;
  insert(second,3);
  insert(second,4);
  insert(second,5);

  Node* answer = addTwoLists(first,second);
  printList(first);
  printList(second);
  printList(answer);
}
