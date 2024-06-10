/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode* , bool>table;
        ListNode* temp = head;
        while(temp!=NULL){
            if(table[temp] == false){
                table[temp] == true;
            }
            else{
                //cycle present
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
};


//another method is slow-fast algp
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL){
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next!= NULL){
            if(slow == fast){
                return true;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        return false;
    }
};