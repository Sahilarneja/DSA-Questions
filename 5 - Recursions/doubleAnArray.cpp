#include <iostream>
#include <vector>
using namespace std;

void doubleArray(int arr[], int index, int size, vector<int>&ans){
    //base case
    if(index>=size){
        return;
    }

    //processing
    for(index=0; index<size; index++){
        ans.push_back(arr[index]*2);
    }

    //recursive call
    doubleArray(arr, index+1, size, ans);
}

int main(){
    int arr[]= {10,20,30,40,50};
    int index=0;
    int size=5;
    vector<int> ans;

    doubleArray(arr, index, size, ans);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}