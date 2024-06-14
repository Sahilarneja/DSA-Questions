// https://leetcode.com/problems/sort-list/submissions/1287806245/
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
    ListNode* findMid(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* slow = head;
        ListNode* fast = head->next; // Start fast one step ahead
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode dummy(-1); // Dummy node to act as the head of the merged list
        ListNode* mptr = &dummy; 

        while (left != NULL && right != NULL) {
            if (left->val < right->val) {
                mptr->next = left;
                left = left->next;
            } else {
                mptr->next = right;
                right = right->next;
            }
            mptr = mptr->next;
        }

        if (left != NULL) {
            mptr->next = left;
        }
        if (right != NULL) {
            mptr->next = right;
        }

        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // Find the midpoint of the list
        ListNode* midNode = findMid(head);
        ListNode* right = midNode->next;
        midNode->next = NULL; // Split the list into two halves
        ListNode* left = head;

        // Recursively sort the two halves
        left = sortList(left);
        right = sortList(right);

        // Merge the sorted halves
        return merge(left, right);
    }
};
