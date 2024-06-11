#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructors
    Node() {
        this->next = NULL;
    }

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void removeALoop(Node* &head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next;
        if (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        if (slow == fast) {
            break;
        }
    }

    if (fast == NULL) {
        return; // No loop found, exit function
    }

    slow = head;

    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    Node* startPoint = slow;
    Node* temp = head;

    while (temp->next != startPoint) {
        temp = temp->next;
    }

    temp->next = NULL;
}


