// https://leetcode.com/problems/reverse-nodes-in-k-group/
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || k == 1)
            return head;
        
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* nextNode = nullptr;
        int pos = 0;
        
        while (pos < k && curr != nullptr) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            pos++;
        }

        if (nextNode != nullptr) {
            head->next = reverseKGroup(nextNode, k);
        } else if (pos < k) {
            // Re-reverse the current group if it has fewer than k elements
            ListNode* rePrev = nullptr;
            ListNode* reCurr = prev;
            ListNode* reNext = nullptr;
            while (reCurr != nullptr) {
                reNext = reCurr->next;
                reCurr->next = rePrev;
                rePrev = reCurr;
                reCurr = reNext;
            }
            return rePrev;
        }
        
        return prev;
    }
};
