// https://leetcode.com/problems/copy-list-with-random-pointer/?envType=study-plan-v2&envId=top-interview-150
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return head;

        // 1) create newList with same values
        Node* curr = head;
        while(curr != NULL){
        Node* newNode = new Node(curr->val);
        newNode->next = curr->next;
        curr->next = newNode;
        curr = newNode->next;
        }

        // 2) copy random pointers
        curr = head;
        while(curr != NULL){
            if(curr->random != NULL){
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // 3) seprate 2 lists
        curr = head;
        Node* newHead = head->next;
        Node* newCurr = newHead;
        while(curr != NULL){
            curr->next = newCurr->next;
            curr = curr->next;
            if(curr != NULL){
                newCurr->next = curr->next;
                newCurr = newCurr->next;
            }
        }
        return newHead;
    }
};