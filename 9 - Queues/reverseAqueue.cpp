#include <iostream>
#include <stack>
#include <queue>
using namespace std;




void reverseUsingRecursion(queue<int>& q){
    if(q.empty()) return;

    int temp = q.front();
    q.pop();

    reverseUsingRecursion(q);
    q.push(temp);
}
void reverse(queue<int>& q){
    stack<int> s;

    while(!q.empty()){
        int frontElement = q.front();
        q.pop();
        s.push(frontElement);
    }

    while(!s.empty()){
        int topElement = s.top();
        s.pop();
        q.push(topElement);
    }
}

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    // reverse(q);
    reverseUsingRecursion(q);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}