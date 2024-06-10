class Solution {
public:
    ListNode* mid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* reverseListUsingRecursion(ListNode* &prev, ListNode* &curr) {
        if(curr == NULL) {
            return prev;
        }
        ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        return reverseListUsingRecursion(prev, curr);
    }

    bool compare(ListNode* head1, ListNode* head2) {
        while( head2 != NULL) {
            if(head1->val != head2->val) {
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        return (head1 == NULL && head2 == NULL); // Ensure both lists are of the same length
    }
        
    

    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return true;
        }

        // Find the middle of the linked list
        ListNode* midNode = mid(head);
        ListNode* head2 = midNode->next;
        midNode->next = NULL;

        // Reverse the second half of the linked list
        ListNode* prev = NULL;
        ListNode* curr = head2;
        head2 = reverseListUsingRecursion(prev, curr);

        // Compare the first half and the reversed second half
        bool ans = compare(head, head2);

        return ans;
    }
};
