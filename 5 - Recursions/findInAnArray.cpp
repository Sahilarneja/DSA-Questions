#include <iostream>
using namespace std;

int find(int arr[], int index, int size, int target){
    
    //base case
    if(index>=size){
        return -1;
    }

    //processing
    if(arr[index] == target){
        return index;
        
    }

    find(arr,index+1,size,target);
}

int main(){
    int arr[]={10,20,30,40,50};
    int size=5;
    int index=0;
    int target=30;

    int result=find(arr,index,size,target);
    cout<<result<<endl;
}