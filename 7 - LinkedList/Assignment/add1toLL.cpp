// https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1
class Solution
{
    public:
    
    Node* reverse(Node* head){
        
        Node* prev = NULL;
        Node* curr = head;

        Node* temp = NULL;
        while(curr != NULL){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        //1) reverse a LL
        head = reverse(head);
        int carry = 1;
        Node* temp = head;
        while(temp != NULL){
            int totalSum = temp->data + carry;
        int digit = totalSum % 10;
        carry = totalSum / 10;
        temp->data = digit;

    
        if(temp->next == NULL && carry > 0){
            temp->next = new Node(carry);
            break;
        }
        temp = temp->next;

        }
        head = reverse(head);
        return head;
        
    }
};