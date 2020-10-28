//https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1#
void removeLoop(Node* head){
    Node* slow = head, *fast = head;
    bool flag = 0;
    while(slow && fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            flag = 1;
            break;
        }
    }
    if(!flag) return;
    Node* marker = slow;
    int count = 1;
    slow = slow->next;
    while(slow!=marker){
        slow = slow->next;
        count++;
    }
    slow = head;
    fast = head;
    for(int i=0;i<count;i++) fast = fast->next;
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }
    marker = slow;
    while(slow->next!=marker) slow = slow->next;
    slow->next = NULL;
    return;
}
