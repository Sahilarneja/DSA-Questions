#include <iostream>
using namespace std;

int findMissingElement(int arr[], int n) {
    int s = 0;
    int e = n - 1;
    int ans = -1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        int diff = arr[mid] - mid;

        if (diff == 1) {
            // Move to the right half
            s = mid + 1;
        } else {
            // Store the answer
            ans = mid;
            // Move to the left half
            e = mid - 1;
        }
    }
    return ans;
}

int main() {
    int arr[] = {1, 2, 3, 4, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Missing element: " << findMissingElement(arr, n) + 1 << endl;

    return 0;
}
