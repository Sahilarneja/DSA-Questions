// https://leetcode.com/problems/merge-two-sorted-lists/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* left, ListNode* right) {
         ListNode* dummy = new ListNode(-1); // Dummy node to act as the head of the merged list
        ListNode* mptr = dummy; 

        while(left!= NULL && right!= NULL){
            if(left->val < right->val){
                mptr->next = left;
                mptr = left;
                left = left->next;
            }
            else{
                mptr->next = right;
                mptr = right;
                right = right->next;
            }
        }

        if(left != NULL){
            mptr->next = left;
        }
        if(right != NULL){
            mptr->next = right;
        }
        ListNode* mergedList = dummy->next;
        delete dummy; 
        return mergedList;
    }
};