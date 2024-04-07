#include <iostream>
using namespace std;

bool checkSorted(int arr[], int size, int index){
    // Base case: if the index reaches the end of the array, the array is sorted
    if(index >= size ){
        return true;
    }

    // Compare the current element with the next element
    if(arr[index] <= arr[index + 1]){
        // If the current element is less than or equal to the next element,
        // recursively check the remaining elements
        return checkSorted(arr, size, index + 1); 
    }
    else {
        // If the current element is greater than the next element,
        // the array is not sorted
        return false;
    }
}

int main(){
    int arr[] = {10, 20, 30, 40, 50, 60};
    int size = 6;
    int index = 1;

    bool isSorted = checkSorted(arr, size, index);

    if(isSorted){
        cout << "Array is sorted" << endl;
    } else {
        cout << "Array is not sorted" << endl;
    }
    
    return 0;
}
