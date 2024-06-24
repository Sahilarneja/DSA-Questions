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
        else if(rear == front-1 || front == 0 && rear == size-1){
            cout<<"Queue is full!"<<endl;
        }

        //circular queue
        else if(rear == size-1 && front != 0){
            rear = 0;
            arr[rear] = data;
            return;
        }
        else{rear++;
        arr[rear] = data;}
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
        //circular queue
        else if(front == size-1){
            arr[front] = -1;
            front = 0;
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

   int getSize() {
        if (front == -1) {
            return 0;
        }
        if (rear >= front) {
            return rear - front + 1;
        } else {
            return size - front + rear + 1;
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

int main() {
    queues q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.print();

    q.pop();
    cout << "Size of queue is: " << q.getSize() << endl;
    cout << "Front element is: " << q.getFront() << endl;
    cout << "Rear element is: " << q.getRear() << endl;
    q.print();

    q.push(6);
    q.print();

    q.pop();
    cout << "Size of queue is: " << q.getSize() << endl;
    cout << "Front element is: " << q.getFront() << endl;
    cout << "Rear element is: " << q.getRear() << endl;
    q.print();

    q.pop();
    cout << "Size of queue is: " << q.getSize() << endl;
    cout << "Front element is: " << q.getFront() << endl;
    cout << "Rear element is: " << q.getRear() << endl;
    q.print();

    return 0;
}