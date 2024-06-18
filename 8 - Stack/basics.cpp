#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<int> st;
    st.push(13);
    st.push(10);
    st.push(20);

    cout<<st.size()<<endl;

    if(st.empty()){
        cout << "true";
    }else{
       cout<< "false";
    }

    cout<<endl;
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.size()<<endl;

}