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

int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    int element = 25;
    insertAtSorted(st, element);

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}
