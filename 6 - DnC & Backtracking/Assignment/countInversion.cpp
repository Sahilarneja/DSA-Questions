#include <iostream>
using namespace std;

long merge(int arr[], int start, int end) {
    int mid = (start + end) / 2;
    long c = 0; 

    int lenLeft = mid - start + 1;
    int lenRight = end - mid;

    int *left = new int[lenLeft];
    int *right = new int[lenRight];

    int k = start;
    for (int i = 0; i < lenLeft; i++) {
        left[i] = arr[k];
        k++;
    }

    k = mid + 1;
    for (int i = 0; i < lenRight; i++) {
        right[i] = arr[k];
        k++;
    }

    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrayIndex = start; 

    while (leftIndex < lenLeft && rightIndex < lenRight) {
        if (left[leftIndex] <= right[rightIndex]) {
            arr[mainArrayIndex] = left[leftIndex];
            leftIndex++;
        } else {
            arr[mainArrayIndex] = right[rightIndex];
            c += lenLeft - leftIndex; //imp
            rightIndex++;
        }
        mainArrayIndex++;
    }

    while (leftIndex < lenLeft) {
        arr[mainArrayIndex] = left[leftIndex];
        leftIndex++;
        mainArrayIndex++;
    }

    while (rightIndex < lenRight) {
        arr[mainArrayIndex] = right[rightIndex];
        rightIndex++;
        mainArrayIndex++;
    }

    delete[] left;
    delete[] right;

    return c; 
}

long mergeSort(int arr[], int start, int end) {
    if (start >= end) {
        return 0;
    }
    long c = 0; 
    int mid = (start + end) / 2;
    c += mergeSort(arr, start, mid);
    c += mergeSort(arr, mid + 1, end);

    c += merge(arr, start, end);
    return c;
}





int main() {
    int arr[] = {8, 4, 1, 2};
    int size = 4;
    int start = 0;
    int end = size - 1;

    long inversions = mergeSort(arr, start, end);
    cout << "Number of inversions: " << inversions << endl;
    return 0;
}
