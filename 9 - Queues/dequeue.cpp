#include <iostream>
using namespace std;


class dequeue{
    public:
    int *arr;
    int front;
    int rear;
    int size;

    dequeue(int size){
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void push_back(int data){
        if(front == -1 && rear == -1){
            //empty
            front = 0;
            rear = 0;
            arr[front] = data;
        }
        else if(rear == size-1 && front ==0 || rear == front-1){
            //full
            cout<<"Overflow"<<endl;
        }
        else if(rear == size-1 && front !=0){
            //circular
            rear = 0;
            arr[rear] = data;
        }
        else{
            //normal flow
            rear++;
            arr[rear] = data;
        }
    }

    void push_front(int data){
         if(front == -1 && rear == -1){
            //empty
            front = 0;
            rear = 0;
            arr[front] = data;
        }
        else if(rear == size-1 && front ==0 || rear == front-1){
            //full
            cout<<"Overflow"<<endl;
        }else if(front == 0 && rear != size-1){
            front = size-1;
            arr[front] = data;
        }else{
            //normal flow
            front--;
            arr[front] = data;
        }
    }

    void pop_front(){
        if(front == -1 && rear == -1){
            //empty
            cout<<"Underflow"<<endl;
        }
        else if(front == rear){
            arr[front] = -1;
            front = -1;
            rear = -1;
            return;
        } else if(front == size-1){
            arr[front] = -1;
            front = 0;
        }else{
            arr[front] = -1;
            front++;
        }
    }

    void pop_back(){
        if(front == -1 && rear == -1){
            //empty
            cout<<"Underflow"<<endl;
        }
        else if(front == rear){
            arr[front] = -1;
            front = -1;
            rear = -1;
            return;
        } else if(rear == 0){
            arr[rear] = -1;
            rear = size-1;
        }else{
            arr[rear] = -1;
            rear++;
        }
    }

    void print() {
       for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
       }
       cout<<endl;
    }


};

int main() {
    dequeue dq(5);

   dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);
    dq.print(); 

    dq.push_front(0);
    dq.print(); 

    dq.push_back(4);
    dq.print(); 

    dq.push_front(-1); 

    dq.pop_front();
    dq.print(); 

    dq.pop_back();
    dq.print(); 

    return 0;
}