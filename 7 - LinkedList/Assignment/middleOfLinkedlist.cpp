
class Solution {
public:

    int getLength(ListNode* head){
        int length = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            length++;
            temp = temp->next;
        }
        return length;
    }
    ListNode* middleNode(ListNode* head) {
        int n = getLength(head);
        int pos = n/2 +1;
        int currPos = 1;
        ListNode* temp = head;
        while(currPos != pos){ 
        // instead of temp we used currPos as pos is int and we can/t compare pointer with int 
            currPos++;
            temp = temp->next;
        }
        return temp;
    }
};



//Method-2 (better)
//SLOW & FAST ALGORITHM
    ListNode* mid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
       while(fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;

    }           