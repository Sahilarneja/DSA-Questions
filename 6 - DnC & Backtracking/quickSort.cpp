#include <iostream>
using namespace std;

void quickSort(int arr[], int start, int end) {
    if (start >= end) {
        return;
    }

    int i = start - 1;
    int j = start;
    int pivot = end;

    while (j <= pivot) {
        if (arr[j] < arr[pivot]) {
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }
    i++;
    swap(arr[i], arr[pivot]);

    quickSort(arr, start, i - 1);
    quickSort(arr, i + 1, end);
}

int main() {
    int arr[] = {7, 1, 2, 6, 8, 5, 4};
    int size = sizeof(arr) / sizeof(arr[0]); 
    int start = 0;
    int end = size - 1;

    quickSort(arr, start, end);
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}