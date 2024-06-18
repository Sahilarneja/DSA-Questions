#include <iostream>
#include <stack>
using namespace std;



int solve(stack<int> &st, int pos) {
    // base case
    if (pos == 1) {
        int ans = st.top();
        //for deletion of middle node instead of saving it just use st.pop()
        return ans;
    }
    
    pos--;
    int temp = st.top();
    st.pop();

    int ans = solve(st, pos);
    st.push(temp);

    return ans;
}


int getMiddle(stack<int> &st) {
    int size = st.size();

    if (st.empty()) {
        return -1;
    } else {
        int pos=0;
        if(size % 2==0){
            //even case
            pos = size/2;
        }else{
            //odd case
            pos = size/2 + 1;
        }
        return solve(st, pos);
    }
}


int main(){
    stack <int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);

    int res = getMiddle(st);
    cout << getMiddle(st) << endl;
    return 0;
    }