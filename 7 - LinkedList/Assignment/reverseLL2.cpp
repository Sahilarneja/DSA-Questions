// https://leetcode.com/problems/reverse-linked-list-ii/?envType=study-plan-v2&envId=top-interview-150
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || left == right) return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* preLeft = dummy;

        for(int i=0;i<left-1;i++){
            preLeft = preLeft->next;
        }

        ListNode* curr = preLeft->next;
        ListNode* preNode = NULL;
        ListNode* tail = curr;
        ListNode* temp;

        for(int i=0; i<=right-left; i++ ){
            temp = curr->next;
            curr->next = preNode;
            preNode = curr;
            curr = temp;
        }

        preLeft->next = preNode;
        tail->next = curr;
        
        return dummy->next;


        
    }
};