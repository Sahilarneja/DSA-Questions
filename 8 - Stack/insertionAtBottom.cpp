#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int> &st, int &element) {
    if (st.empty()) {
        st.push(element);
        return;
    }

    int temp = st.top();
    st.pop();

    solve(st, element);

    // backtrack
    st.push(temp);
}

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    int element = 0;
    solve(st, element);

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}
