#include <iostream>
#include <stack>
using namespace std;

void insertAtSorted(stack<int> &st, int element){
    if(st.empty() || st.top() <= element){
        st.push(element);
        return;
    }
    int temp = st.top();
    st.pop();

    insertAtSorted(st, element);
    st.push(temp);
}

void sortStack(stack<int> &st){
    if(st.empty()){
        return;
    }
    int temp = st.top();
    st.pop();

    sortStack(st);
    insertAtSorted(st, temp);
}

int main(){
    stack<int> st;
    st.push(20);
    st.push(10);
    st.push(50);
    st.push(5);

    int element = 25;
    sortStack(st);

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}
