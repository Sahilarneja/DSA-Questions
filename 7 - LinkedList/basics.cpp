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
        this->data=data;
        this->next=NULL;
    }
};

void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int getLength(Node* &head){
    int length=0;
    Node* temp = head;
    while(temp !=NULL){
        length++;
        temp=temp->next;
    }
    return length; 
}

int main(){

    Node first(10);
    Node second(20);
    Node third(30);
    Node fourth(40);

    Node* head = &first;
    first.next = &second;
    second.next = &third;
    third.next = &fourth;
    fourth.next = NULL;

    print(head);

    cout<<"Length: "<<getLength(head)<<endl;
}