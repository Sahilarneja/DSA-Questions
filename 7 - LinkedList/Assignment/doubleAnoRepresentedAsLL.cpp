// https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/submissions/1290868949/
class Solution {
public:

    void solve(ListNode* head, int &carry){
        if(head == NULL){
            return ;
        }
        solve(head->next, carry);

        //1 case
        int prod = head->val * 2 + carry;
        head->val = prod % 10;
        carry = prod / 10;
    }
    ListNode* doubleIt(ListNode* head) {
        int carry = 0;
        solve(head, carry);
        if(carry != 0){
            ListNode* carryNode = new ListNode(carry);
            carryNode->next = head;
            head = carryNode;
        }
        return head;
    }
};