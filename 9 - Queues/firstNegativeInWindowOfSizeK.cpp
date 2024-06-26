#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> ans(vector<int> &arr, int k) {
    int n = arr.size();
    vector<int> res;
    queue<int> q;

    for(int i=0;i<k;i++){
        if(arr[i] < 0){
            q.push(arr[i]);
        }
    }

    // Store the result for the first window
    if (!q.empty()) {
        res.push_back(q.front());
    } else {
        res.push_back(0);
    }

     for (int i = k; i < n; i++) {
        // Remove the element that is out of this window
        if (!q.empty() && q.front() == arr[i - k]) {
            q.pop();
        }

        // Add the new element (current window's last element)
        if (arr[i] < 0) {
            q.push(arr[i]);
        }

        // Store the result for the current window
        if (!q.empty()) {
            res.push_back(q.front());
        } else {
            res.push_back(0);
        }
    }

    return res;
}

int main() {
     vector<int> arr;
    arr.push_back(12);
    arr.push_back(-1);
    arr.push_back(-7);
    arr.push_back(8);
    arr.push_back(-15);
    arr.push_back(30);
    arr.push_back(16);
    arr.push_back(28);

    int k = 3;
    vector<int> result = ans(arr, k);

    for (int i : result) {
        cout << i << " ";
    }

    return 0;
}