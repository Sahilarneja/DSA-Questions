// https://leetcode.com/problems/reverse-linked-list/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};

//USING RECURSION

class Solution {
public:

    ListNode* reverseListUsingRecursion(ListNode* &prev, ListNode* &curr){

        if(curr == NULL){
            return prev;
        }
        ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;

        ListNode* recursionKaAns = reverseListUsingRecursion(prev, curr);
        return recursionKaAns;

    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

       return reverseListUsingRecursion(prev, curr);
    }
};  