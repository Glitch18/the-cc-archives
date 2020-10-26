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

struct Node* addTwoLists(struct Node* first, struct Node* second){
    reverseList(first,first);
    reverseList(second,second);
    Node* ans = NULL;

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

    //reverseList(ans,ans);
    return ans;
}

void printList(Node* const head){
  Node* curr = head;
  while(curr!=NULL){
    cout << curr->data << " ";
    curr = curr->next;
  }
  cout << "\n";
}

int main(){
  Node* first = NULL;
  insert(first,4);
  insert(first,5);
  Node* second = NULL;
  insert(second,3);
  insert(second,4);
  insert(second,5);

  printList(first);
  printList(second);
}
