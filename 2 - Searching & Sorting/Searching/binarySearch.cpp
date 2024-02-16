// https://leetcode.com/problems/binary-search/submissions/1177204833/?
#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target){
    int start=0;
    int end=n-1;
    int mid=(start+end)/2;

    while(start<=end){
        //found
        if(arr[mid]==target){
            //return index of mid
            return mid;
        }
        else if(target>arr[mid]){
            //right m jao
            start=mid+1;
        }
        else if(target<arr[mid]){
            //left m jao
            end=mid-1;
        }
        //mid update
        mid=(start+end)/2;
    }
    //agar yha tk pohoche ho
    //iska matlab element nahi mila
    return -1;
}


int main(){
    int arr[]={10,20,30,40,50,60,70,80,90};
    int target=90;
    int n=9;

    int ansIndex=binarySearch(arr,n,target);
    if(ansIndex ==-1){
        cout<<"Element not found "<<endl;
    }else{
        cout<<"Element found at index "<<ansIndex<<endl;
    }

    return 0;
}