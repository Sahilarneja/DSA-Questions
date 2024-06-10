#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node() {
        this->next = NULL;
    }

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        tail->next = head;
    } else {
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }
}
int getLength(Node* &head){
    int length = 0;
    Node* temp = head;
    do{
        length++;
        temp = temp->next;
    }while(temp != head);
    return length;
}
void insertAtTail(Node* &head, Node* &tail, int data){
    Node* newNode = new Node(data);
    if(tail == NULL){ 
        tail = newNode;
        head = newNode;
        tail->next = head; 
    } else {
        tail->next = newNode;
        tail = newNode;
        tail->next = head; 
    }
}

void insertAtPos(Node* &head, Node* &tail, int data, int pos){
    if(pos<=1){
        insertAtHead(head, tail, data);
        return;
    }else if(pos >getLength(head)){
        insertAtTail(head, tail, data);
        return;
    }
    else{
    Node* newNode = new Node(data);
    Node* temp = head;
    for(int i=0;i<pos-1;i++){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    if(temp == tail){
        tail = newNode;
        tail->next = head;
    }
    }
    
}

void deleteFromhead(Node* &head, Node* &tail){
    if(head == NULL){
        return;
    }
    if(head == tail){
        head = NULL;
        tail = NULL;
    }
    else{
        head = head->next;
        tail->next = head;
        
    }
}

void deleteFromTail(Node* &head, Node* &tail){
    if(tail == NULL){
        return;
    }
    if(head == tail){
        head=NULL;
        tail=NULL;
    }
    else{
    Node* temp = head;
    while(temp->next != tail){
        temp = temp->next;
    }
    tail = temp;
    tail->next = head;
    }
}

void deleteFromPos(Node* &head, Node* &tail,  int pos){
    if(head == NULL){
        return;
    }
    if(head == tail){
        head =NULL;
        tail = NULL;
    }
    else{
        Node* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != head; i++) {
        temp = temp->next;
    }
    
    if (temp->next == head) { 
        return;
    }
    
    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    
    if (toDelete == tail) { 
        tail = temp;
        tail->next = head; 
    }
    
    delete toDelete;
}
}

void print(Node* head) {
    if (head == NULL) {
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    // insertAtHead(head, tail, 10);
    // insertAtTail(head, tail, 20);
    insertAtPos(head, tail,10,1);
    insertAtPos(head, tail,30,2);
    insertAtPos(head, tail,20,3);
    insertAtHead(head, tail, 5);
    // insertAtPos(head, tail,40,4);
    print(head);

    // deleteFromhead(head, tail);
    // deleteFromTail(head, tail);
    deleteFromPos(head, tail, 2);
    print(head);

    return 0;
}
