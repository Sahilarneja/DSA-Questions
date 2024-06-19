#include <iostream>
#include<stack>
using namespace std;


vector<int> smallesElement(int *arr, int size, vector<int> &ans){
    stack<int> st;
    st.push(-1);

    for(int i=size-1; i>=0; i--){
        int curr = arr[i];
        while(st.top()>= curr){
            st.pop();
        }
        ans.push_back(st.top());
        st.push(curr);

    }
    return ans;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> ans(n);

    ans = smallesElement(arr, n, ans);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;

}