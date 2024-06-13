// https://www.naukri.com/code360/problems/delete-n-nodes-after-m-nodes-of-a-linked-list_668903?leftPanelTabValue=SUBMISSION
Node *getListAfterDeleteOperation(Node *head, int n, int m)
{
	if(head == NULL){
			return head;
		}
		Node* curr = head;
		while(curr != NULL){

			for(int i=0;i<m-1 && curr != NULL; i++){
				curr = curr->next;
			}
			if (curr == nullptr) {
            break;
        }
			Node* temp = curr->next;
			for(int i=0;i<n && temp != NULL; i++){
				Node* nodeToDelete = temp;
				temp = temp->next;
				delete nodeToDelete;
			}
			curr->next = temp;
			curr = temp;
		}
		return head;
	}