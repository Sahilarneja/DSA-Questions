#include <iostream>
using namespace std;

int binarySearch(int arr[], int s, int e, int target){
    if(s > e){
        return -1;
    }
    
    int mid = s + (e-s)/2;
    if(arr[mid] == target){
        return mid;
    }

    if(arr[mid] < target){
        
        bool aageKaAns = binarySearch(arr, mid+1, e , target);
        return aageKaAns;
    }else{
        e=mid-1;
        bool aageKaAns = binarySearch(arr, s , mid-1 , target);
    }
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};
   int size = 8;
   int start = 0;
   int end = size-1;

   int target = 9;

   bool found = binarySearch(arr, start, end, target);
   if(found){
    cout<<"target found"<<endl;
   }else{
    cout<<"target not found"<<endl;
   }
}