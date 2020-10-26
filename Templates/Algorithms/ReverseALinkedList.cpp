struct Node* reverseList(struct Node* head,struct Node* curr){
    if(curr->next==NULL){
        head = curr;
        return curr;
    }
    reverseList(head,curr->next)->next = curr;
    curr->next = NULL;
    return curr;
}
