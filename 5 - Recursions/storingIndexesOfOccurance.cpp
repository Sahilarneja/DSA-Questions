#include <iostream>
#include <vector>
using namespace std;

void storingIndexes(int arr[], int size, int index, int target, vector<int> &ans){
    //base case
    if(index>=size){
        return;
    }

    //processing
    if(arr[index]==target){
        ans.push_back(index);
    }

    //recursive call
    storingIndexes(arr, size, index+1, target, ans);
}

int main(){
    int arr[]= {10,20,10,30,10};
    int size=5;
    int index=0;
    int target=10;
    vector<int> ans;

    storingIndexes(arr, size, index, target, ans);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}