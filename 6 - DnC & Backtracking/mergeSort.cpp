#include <iostream>
using namespace std;

void merge(int arr[], int s, int e){

    int mid = (s+e)/2;

    int lenLeft = mid - s +1;
    int lenRight = e - mid;

    int *left = new int[lenLeft];
    int *right = new int[lenRight];

    // Copy values from the original array to the left array
    int k = s;
    for(int i=0; i<lenLeft; i++){
        left[i] = arr[k];
        k++;
    }

    // Copy values from the original array to the right array
    k = mid+1;
    for(int i=0; i<lenRight; i++){
        right[i] = arr[k];
        k++;
    }

    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrayIndex = s; // Start index of the main array

    // Merge the left and right arrays into the main array
    while(leftIndex < lenLeft && rightIndex < lenRight){
        if(left[leftIndex] < right[rightIndex]){
            arr[mainArrayIndex] = left[leftIndex];
            leftIndex++;
        } else {
            arr[mainArrayIndex] = right[rightIndex];
            rightIndex++;
        }
        mainArrayIndex++;
    }

    // Copy remaining elements of left array if any
    while(leftIndex < lenLeft){
        arr[mainArrayIndex] = left[leftIndex];
        leftIndex++;
        mainArrayIndex++;
    }

    // Copy remaining elements of right array if any
    while(rightIndex < lenRight){
        arr[mainArrayIndex] = right[rightIndex];
        rightIndex++;
        mainArrayIndex++;
    }

    // Free dynamically allocated memory
    delete [] left;
    delete [] right;
}

void mergeSort(int arr[], int s, int e){
    if(s>e){
        return;
    }
    if(s == e){
        return;
    }

    int mid = (s+e)/2;

    //for left array
    mergeSort(arr, s, mid);

    //for right array
    mergeSort(arr, mid+1, e);

    merge(arr, s, e);


}

int main(){
    int arr[] = {2,1,9,7,4,6};
    int size = 6;
    int s = 0;
    int e = size-1;

    cout<<"Before Merge Sort"<<endl;
    for(int i=0; i<size; i++){
        cout<< arr[i]<< " ";
    }
    cout<<endl;

     mergeSort(arr, s, e);


     cout<<"After Merge Sort"<<endl;
    for(int i=0; i<size; i++){
        cout<< arr[i]<< " ";
    }
    cout<<endl;
}