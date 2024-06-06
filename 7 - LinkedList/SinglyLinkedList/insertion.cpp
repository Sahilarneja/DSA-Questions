#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node() {
        this->data = 0;  
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
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void insertAtTail(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);
    if (tail == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

int getLength(Node* head) {
    int length = 0;
    Node* temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    return length;
}

void insertAtPos(Node* &head, Node* &tail, int data, int pos){
    int length = getLength(head);
    if (pos <= 1) {
        insertAtHead(head, tail, data);
    } else if (pos > length) {
        insertAtTail(head, tail, data);
    } else {
        Node* newNode = new Node(data);
        Node* temp = head;
        for (int i = 1; i < pos - 1; i++) { 
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        // Update tail if the new node is inserted at the last position
        if (newNode->next == NULL) {
            tail = newNode;
        }
    }
}

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;  
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    insertAtPos(head, tail, 2, 1);
    insertAtPos(head, tail, 3, 2);
    insertAtPos(head, tail, 1, 1); // Insert at the head
    insertAtPos(head, tail, 4, 4); // Insert at the tail

    print(head);

    return 0;
}
