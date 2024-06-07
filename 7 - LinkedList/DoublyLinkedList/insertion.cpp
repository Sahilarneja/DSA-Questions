#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node()
    {
        this->prev = NULL;
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void print(Node *&head, Node *&tail)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        newNode->prev = NULL;
        newNode->next = NULL;
        head = newNode;
        tail = newNode;
    }
    else
    {

        Node *newNode = new Node(data);
        newNode->prev = NULL;
        head->prev = newNode;
        newNode->next = head;

        head = newNode;
    }
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (tail == NULL)
    {
        Node *newNode = new Node(data);
        newNode->prev = NULL;
        newNode->next = NULL;
        head = newNode;
        tail = newNode;
    }
    else
    {
        Node *newNode = new Node(data);
        tail->next = newNode; 
        newNode->prev = tail; 
        tail = newNode;
    }
}

int getLength(Node *&head, Node *&tail)
{
    int length = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}

void insertAtPos(Node *&head, Node *&tail, int data, int pos)
{
    if (pos <= 1)
    {
        insertAtHead(head, tail, data);
    }
    else if (pos > getLength(head, tail))
    {
        insertAtTail(head, tail, data);
    }
    else
    {
        Node *newNode = new Node(data);
        Node *temp = head;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        Node *temp2 = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = temp2;

        if (newNode->next == NULL)
        {
            tail = newNode;
        }
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    // insertAtHead(head, tail, 1);
    // insertAtHead(head, tail, 2);
    // insertAtTail(head, tail, 3);
    insertAtPos(head, tail, 1, 1); //at head
    insertAtPos(head, tail, 8, 2); //at head
    insertAtPos(head, tail, 6, 3); //at head

    insertAtPos(head, tail, 2, 4); //at tail
    insertAtPos(head, tail, 3, 3);
    print(head, tail);
}