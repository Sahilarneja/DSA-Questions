#include <iostream>
#include <queue>
using namespace std;

int main(){
    //creation
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);

    cout<<"Size of queue is: "<<q.size()<<endl;

    q.pop();
    if(q.empty()){
        cout<<"Queue is empty"<<endl;
    }else{
        cout<<"Queue is Not empty"<<endl;
    }
    cout<<"Size of queue is: "<<q.size()<<endl;
    cout<<"Front of queue is: "<<q.front()<<endl;
    cout<<"Back of queue is: "<<q.back()<<endl;

    q.pop();
    cout<<"Size of queue is: "<<q.size()<<endl;

    return 0;
}