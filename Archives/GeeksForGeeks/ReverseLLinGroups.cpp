//https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1

struct node* goToTheEnd(struct node* start){
  node* curr = start;
  while(curr->next!=NULL) curr = curr->next;
  return curr;
}

int reverse(struct node* head,int k){
  node* prev,next;
  node* curr=head;

  node** master = &head;

  int count=0;

  while(curr!=NULL){
    if(count%k==0) prev=NULL; //First
    next = curr->next;
    curr->next = prev;
    prev=curr;
    curr=next;
    if((count+1)%k==0 || curr==NULL){
      *master = prev;
      &master = &(goToTheEnd(prev)->next);
    }
  }
}
