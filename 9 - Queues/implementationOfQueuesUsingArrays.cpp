#include<iostream>
using namespace std;

class queues{
    public:
    int *arr;
    int size;
    int front, rear;

    queues(int size){
       arr = new int[size];
       this->size = size;
       front = -1;
       rear = -1;

    }


    void push(int data){
        if(rear == -1 && front == -1){
            front = 0;
            rear = 0;
            arr[rear] = data;
            return;
        }
        if(rear == size-1){
            cout<<"Queue is full!"<<endl;
        }
        rear++;
        arr[rear] = data;
    }

    void pop(){
        if(front == -1 && rear == -1){
            cout<<"Queue is empty!"<<endl;
        }
        else if(front == rear){
            arr[front]  = -1;
            front = -1;
            rear = -1;
            
        }
        else{
            arr[front] = -1;
            front++;
        }
    }

    bool isEmpty(){
        if(front == -1 && rear == -1){
            return true;
        }else{
            return false;
        }
    }

    int getSize(){
        if(front == -1){
            return -1;
        }else{
        int size = rear - front + 1;
        return size;
        }
    }

    int getFront(){
        if(front == -1){
            return -1;
        }else{
        return arr[front];
        }
        
    }

    int getRear(){
        if(rear == -1){
            return -1;
        }else{
        return arr[rear];
        }
    }

    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    queues q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.print();

    q.pop();
    cout<<" size of queue is : "<<q.getSize()<<endl;
    cout<< "front element is : "<<q.getFront()<<endl;
    cout<< "rear element is : "<<q.getRear()<<endl;
    q.print();
    q.pop();
    cout<<" size of queue is : "<<q.getSize();
    cout<< "front element is : "<<q.getFront()<<endl;
}