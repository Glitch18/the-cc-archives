//https://leetcode.com/problems/rotate-list/
class Solution {
public:
    void rotateList(ListNode* &head){

        ListNode* curr=head;
        ListNode* prev=NULL;

        if(curr->next==NULL) return;

        while(curr->next!=NULL){
            prev = curr;
            curr = curr->next;
        }

        curr->next = head;
        prev->next = NULL;
        head = curr;
        return;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return NULL;
        ListNode* curr = head;
        int count=0;

        while(curr!=NULL){
            count++;
            curr=curr->next;
        }

        k = k%count;

        while(k--) rotateList(head);
        return head;
    }
};
