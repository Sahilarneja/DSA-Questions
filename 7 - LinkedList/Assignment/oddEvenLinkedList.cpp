// https://leetcode.com/problems/odd-even-linked-list/
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* head1 = head;
        ListNode*  head2 = head->next;
        ListNode* evenHead  = head2;

        while(head2 != NULL && head2->next != NULL){
            head1->next = head2->next;
            head1 = head1->next;

            head2->next = head1->next;
            head2 = head2->next;
        }
        head1->next = evenHead;
        return head;
    }
};