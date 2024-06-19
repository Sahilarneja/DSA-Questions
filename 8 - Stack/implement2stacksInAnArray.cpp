#include <iostream>
#include <string>
using namespace std;

class solve{
    public:
    int *arr;
    int size;
    int top1;
    int top2 ;


    solve(int size){
        arr = new int[size];
        top1 = -1;
        top2 = size;
        this->size = size;
    }

    void push1(int data){
        if(top2 - top1 == 1){
            cout << "Stack Overflow" << endl;
            return;
        }
        top1++;
        arr[top1] = data;
    }

    void push2(int data){
        if(top2 - top1 == 1){
            cout << "Stack Overflow" << endl;
            return;
        }
        top2--;
        arr[top2] = data;
    }

    void pop1(){
        if(top1 == -1){
            cout << "Stack Underflow" << endl;
            return;
        }
        arr[top1] = 0;
        top1--;
    }

    void pop2(){
        if(top2 == size){
            cout << "Stack Underflow" << endl;
            return;
        }
        arr[top2] = 0;
        top2++;
    }

    void print() {
        cout << "Stack 1: ";
        for (int i = 0; i <= top1; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        cout << "Stack 2: ";
        for (int i = size - 1; i >= top2; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;

        cout<< "complete stack" << endl;
        for(int i=0;i<size;i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    solve s(5);

    s.push1(1);
    s.push1(2);
    s.push2(3);
    s.push2(4);
    s.push1(5);
    // s.push2(6);
    s.print();

    s.pop1();
    s.pop2();
    s.print();

    return 0;
}