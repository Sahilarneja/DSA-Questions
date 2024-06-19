#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> smallestElement(int *arr, int size, vector<int> &ans) {
    stack<int> st;
    st.push(-1);

    for (int i = size - 1; i >= 0; i--) {
        int curr = arr[i];
        while (st.top() >= curr) {
            st.pop();
        }
        ans[i] = st.top();
        st.push(curr);
    }
    return ans;
}

int main() {
    int arr[] = {4, 1, 6, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> ans(n);

    ans = smallestElement(arr, n, ans);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
