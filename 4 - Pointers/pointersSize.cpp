#include <iostream>
using namespace std;

// When you pass an array to a function in C++, it decays into a pointer to its first element.
// In other words, arr in the solve function is actually a pointer, not an array. Therefore, 
// sizeof(arr) inside the solve function will give you the size of a pointer, not the size of the original array.


void solve(int *arr, int size){
    cout<< "Size of array inside solve function is: " << sizeof(arr) << endl;
}

int main(){
    int arr[] = {10,20,30,40,50};
    cout<< "Size of array: " << sizeof(arr)<<endl;
    solve(arr,4);
}