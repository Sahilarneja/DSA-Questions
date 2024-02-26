#include <iostream>
using namespace std;

int firstOddOccuringElement(int arr[], int n) {
    int s = 0;
    int e = n - 1;

    while (s <= e) {
        int mid = s + (e - s) / 2;

        // single element
        if (s == e) {
            return s;
        }

        // mid check => even or odd
        if (mid % 2 == 1) {
            if (mid - 1 >= 0 && arr[mid] == arr[mid - 1]) {
                // move to the right
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        } else {
            // even
            if (mid + 1 < n && arr[mid] == arr[mid + 1]) {
                // move to the right
                s = mid + 2;
            } else {
                // either on right part / on ans itself
                // e=mid-1 se ans lost ho skta h
                e = mid;
            }
        }
    }
    return -1;
}

int main() {
    int arr[] = {10, 10, 2, 2, 3, 3, 2, 5, 5, 6, 6, 7, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    int ansIndex = firstOddOccuringElement(arr, n);

    if (ansIndex != -1) {
        cout << "Final Ans is: " << arr[ansIndex] << endl;
    } else {
        cout << "No odd occurring element found." << endl;
    }

    return 0;
}


