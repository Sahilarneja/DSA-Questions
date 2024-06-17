// https://leetcode.com/problems/merge-nodes-in-between-zeros/submissions/1290792286/
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        ListNode* lastNode = 0;
        int sum = 0;
        while(fast != NULL){
            if(fast->val != 0){
                sum += fast->val;
            }
            else{
                //fast is 0
                slow->val = sum;
                lastNode = slow;
                slow = slow->next;
                sum = 0;
            }
            fast = fast->next;
        }
        ListNode* temp = lastNode->next;
        lastNode->next = NULL;

        while(temp!=NULL){
            ListNode* nxt = temp->next;
            delete temp;
            temp = nxt; 
        }
        return head;
    }
};