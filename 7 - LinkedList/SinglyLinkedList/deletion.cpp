#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(){
        this->next = NULL;
    }

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};  

void insertAtHead(Node* &head, Node* &tail, int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
}

void insertAtTail(Node* &head, Node* &tail, int data){
    if(tail == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        Node* newNode = new Node(data);
        tail->next = newNode; 
        tail = newNode; 
    }
}

int getLength(Node* head){
    int length = 0;
    Node* temp = head;
    while(temp != NULL){
        length++;
        temp = temp->next;
    }
    return length;
}

void insertAtPos(Node* &head, Node* &tail, int data, int pos){
    if(pos <= 1){
        insertAtHead(head, tail, data);
    }
    else if(pos > getLength(head)){
        insertAtTail(head, tail, data);
    }
    else{
        Node* newNode = new Node(data);
        Node* temp = head;
        for(int i = 1; i < pos - 1; i++){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;

        if(newNode->next == NULL){
            tail = newNode;
        }
    }
}

void deleteFromHead(Node* &head, Node* &tail){
    if(head == NULL){
        return;
    } else {
        Node* temp = head;
        head = head->next;
        if (head == NULL) { 
            tail = NULL;
        }
        delete temp;
    }
}

void deleteFromTail(Node* &head, Node* &tail) {
    if (tail == NULL) {
        return;
    }

    if (head == tail) { 
        delete head;
        head = NULL;
        tail = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next != tail) { 
        temp = temp->next;
    }

    delete tail; 
    tail = temp;
    tail->next = NULL;
}

void deleteFromPos(Node* &head, Node* &tail, int pos){
    if(pos <= 1){
        deleteFromHead(head, tail);
    }
    else if(pos >= getLength(head)){
        deleteFromTail(head, tail);
    }
    else{
        Node* temp = head;
        for(int i = 1; i < pos - 1; i++){
            temp = temp->next;
        }
        Node* temp2 = temp->next; // Node to delete
        temp->next = temp2->next;
        delete temp2; 

        if(temp->next == NULL){
            tail = temp;
        }
    }
}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtPos(head, tail, 15, 3);
    insertAtPos(head, tail, 25, 1);
    insertAtPos(head, tail, 35, 2);
    print(head); 

    deleteFromHead(head, tail);
    deleteFromTail(head, tail);
    deleteFromPos(head, tail, 2);
    print(head); 
    return 0;
}
