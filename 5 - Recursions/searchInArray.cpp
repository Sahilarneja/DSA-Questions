#include <iostream>
using namespace std;

bool search(int arr[], int size, int target, int index){

    //base case
    if(index>=size){
        return false;
    }
    
    //processing
    if(arr[index]==target){
        return true;
    }
     
    // recursive call
    return search(arr, size, target, index+1);
}

int main(){
    int arr[]={10,20,30,40,50};
    int size=5;
    int target=50;
    int index=0;
    int result = search(arr, size, target, index);
    cout<< "Target found: " << result << endl;
}