class Solution{
public:

    int getLength(Node* head){
        int length = 0;
        Node* temp = head;
        while(temp != NULL){
            length++;
            temp = temp->next;
            
        }
        return length;
    }
    int getNthFromLast(Node *head, int n)
    {
          int length = getLength(head);
          if(n>length){
              return -1;
          }
          Node* temp = head;
          for(int i=0;i<length-n;i++){
              temp = temp->next;
          }
          int ans = temp->data;
          return ans;
    }
};
