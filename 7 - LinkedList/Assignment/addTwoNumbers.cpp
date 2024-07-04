https://leetcode.com/problems/add-two-numbers/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(0);
        ListNode* ptr = result;

        int carry = 0;

        while(l1 !=  NULL || l2 != NULL){
            int sum = carry;

            if(l1 != NULL){
               sum += l1->val;
                l1 = l1->next;
            }

            if(l2 != NULL){
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            sum = sum % 10;

            ptr->next = new ListNode(sum);
            ptr = ptr->next;
        }

        if (carry > 0) {
            ptr->next = new ListNode(carry);
        }
        
        return result->next;
    }
};