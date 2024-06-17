// https://leetcode.com/problems/rotate-list/
class Solution {
public:
    int getLength(ListNode* head){
        int length = 0;
        ListNode* temp = head;
        while(temp!= NULL){
            length++;
            temp = temp->next;
        }
        return length;
    }
    ListNode* rotateRight(ListNode* head, int k) {
         if (!head || !head->next || k == 0) {
            return head;
        }
        int length = getLength(head);
        int actualRotateK = k % length;

        if(actualRotateK == 0){
            return head;
        }

        int pos = length - actualRotateK - 1;
        ListNode* temp = head;
        for(int i=0;i<pos;i++){
            temp = temp->next;
        }
        ListNode* newHead = temp->next;
        temp->next = NULL;

        
        ListNode* it = newHead;
        while (it->next != NULL) {
            it = it->next;
        }
        it->next = head;

        return newHead;


    }
};