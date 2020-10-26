/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void insert(ListNode* &head,int x){
        if(head==NULL) head = new ListNode(x);
        else{
            ListNode* curr = head;
            while(curr->next!=NULL) curr = curr->next;
            curr->next = new ListNode(x);
        }
    }

    ListNode* reverseList(ListNode* &head,ListNode* curr){
        if(curr->next==NULL){
            head = curr;
            curr->next = NULL;
            return curr;
        }
        else{
            reverseList(head,curr->next)->next = curr;
            curr->next = NULL;
            return curr;
        }
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = NULL;
        bool carry = false;
        while(l1!=NULL || l2!=NULL){
            int digit=0;
            if(l1){
                digit+=l1->val;
                l1 = l1->next;
            }
            if(l2){
                digit+=l2->val;
                l2 = l2->next;
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

        return ans;
    }
};
