#include <iostream>
using namespace std;

class stack{
    public:
    int* arr;
    int top;
    int size;

    stack(int size){
        arr = new int[size];
        this->top = -1;
        this->size = size;
        }

        void push(int data){
            if(top == size-1){
                cout<<"Stack overflow!"<<endl;
            }else{
            top++;
            arr[top] = data;
            }
        }

        int pop(){
            if(top == -1){
                cout<<"Stack underflow!"<<endl;
                return -1;
            }else{
            int data = arr[top];
            top--;
            return data;
            }
        }

        bool isEmpty(){
            if(top == -1){
                return true;
            }else{
                return false;
            }
        }

        int getTop(){
            return arr[top];
        }

        int getSize(){
            return top+1;
        }

        void print(){
            for(int i=0;i<getSize();i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};
int main(){
    stack st(8);
    st.push(10);
    st.push(20);
    st.pop();
    st.push(30);
    st.getSize();
    st.print();
    cout<< st.isEmpty()<<endl;
    cout<<st.getSize()<<endl;;
    cout<< st.getTop();
    

    return 0;
}