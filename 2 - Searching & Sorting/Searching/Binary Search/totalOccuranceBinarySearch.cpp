#include <iostream>
using namespace std;

int findFirstOccurance(int arr[],int n,int target){
    int s=0;
    int e=n-1;
    int mid=(s+e)/2;
    int ans=-1;

    while(s<=e){
        if(arr[mid]==target){
            //ans store
            ans=mid;
            //left m jao
            e=mid-1;
        }
        else if(target>arr[mid]){
            //right m jao
            s=mid+1;
        }
        else if(target < arr[mid]){
            e=mid-1;
        }

        mid=(s+e)/2;

    }
    return ans;
}

int findLastOccurance(int arr[],int n,int target){
    int s=0;
    int e=n-1;
    int mid=(s+e)/2;
    int ans=-1;

    while(s<=e){
        if(arr[mid]==target){
            //ans store
            ans=mid;
            //right m jao
            s=mid+1;
        }else if(target>arr[mid]){
            //right m jao 
            s=mid+1;
        }else if(target<arr[mid]){
            //left m jao
            e=mid-1;
        }
        mid=(s+e)/2;
    }
    return ans;
}

int findTotalOccurance(int arr[], int n, int target){
    int firstOccurance=findFirstOccurance(arr,n,target);
    int lastOccurance=findLastOccurance(arr,n,target);
    int totalOccurance=lastOccurance-firstOccurance+1;
    return totalOccurance;
} 

int main(){
    int arr[]={10,20,30,30,30,30,70,80,90};
    int target=30;
    int n=9;

    int ansIndex=findTotalOccurance(arr,n,target);
    if(ansIndex ==-1){
        cout<<"Element not found "<<endl;
    }else{
        cout<<"Total Elements found: "<<ansIndex<<endl;
    }

    return 0;
}