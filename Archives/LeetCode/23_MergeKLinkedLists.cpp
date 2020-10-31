//https://leetcode.com/problems/merge-k-sorted-lists/
class Solution {
public:
    void mergeList(ListNode* &oneOriginal,ListNode* two){
        //merge two into one
        ListNode** prev = &oneOriginal;
        ListNode* one = oneOriginal;

        while(two!=NULL && one!=NULL){
            if(one->val > two->val){
                *prev = two;
                prev = &((*prev)->next);
                two = two->next;
            }
            else{
                *prev = one;
                prev = &((*prev)->next);
                one = one->next;
            }
        }

        while(one!=NULL){
            *prev = one;
            prev = &((*prev)->next);
            one = one->next;
        }

        while(two!=NULL){
            *prev = two;
            prev = &((*prev)->next);
            two = two->next;
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        mergeList(lists[0],NULL);

        for(int i=1;i<lists.size();i++) mergeList(lists[0],lists[i]);

        return lists[0];
    }
};

// Divide and conquer approach===========================

class Solution {
public:
    void mergeList(ListNode* &oneOriginal,ListNode* two){
        //merge two into one
        ListNode** prev = &oneOriginal;
        ListNode* one = oneOriginal;

        while(two!=NULL && one!=NULL){
            if(one->val > two->val){
                *prev = two;
                prev = &((*prev)->next);
                two = two->next;
            }
            else{
                *prev = one;
                prev = &((*prev)->next);
                one = one->next;
            }
        }

        while(one!=NULL){
            *prev = one;
            prev = &((*prev)->next);
            one = one->next;
        }

        while(two!=NULL){
            *prev = two;
            prev = &((*prev)->next);
            two = two->next;
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        if(lists.size()==1) return lists[0];

        if(lists.size()%2!=0){ //OddNumber of Linked Lists
            mergeList(lists[0],lists[1]);
            lists.erase(lists.begin()+1); //erase 2nd element.
        }

        while(lists.size()>1){
            for(int i=1;i<lists.size();i+=2){ //6 nodes : 1,3,5
                mergeList(lists[i-1],lists[i]);
            }
            int i = 1;
            while(i<lists.size()){
                lists.erase(lists.begin()+i);
                i++;
            }
        }
        return lists[0];
    }
};
