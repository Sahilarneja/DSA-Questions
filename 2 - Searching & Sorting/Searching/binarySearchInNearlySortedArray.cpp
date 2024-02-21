#include <iostream>
using namespace std;

int searchNearlySorted(int arr[], int n, int target) {
    int s = 0;
    int e = n - 1;

    while (s <= e) {
        int mid = s + (e - s) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        
        if (mid - 1 >= s && arr[mid - 1] == target) {
            return mid - 1;
        }

        if (mid + 1 <= e && arr[mid + 1] == target) {
            return mid + 1;
        }

        if (target > arr[mid]) {
            // Search in the right half
            s = mid + 2;
        } else {
            // Search in the left half
            e = mid - 2;
        }
    }
    return -1;
}

int main() {
    int arr[] = {20, 10, 30, 50, 40, 70, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 60;
    
    int targetIndex = searchNearlySorted(arr, n, target);

    if (targetIndex == -1) {
        cout << "Element not found" << endl;
    } else {
        cout << "Element found at index: " << targetIndex << endl;
    }

    return 0;
}
