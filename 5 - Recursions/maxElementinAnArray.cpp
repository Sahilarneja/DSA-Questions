#include <iostream>
#include <climits>
using namespace std;

void findMax(int arr[], int size, int index, int &maxNum){

    //base case
    if(index>=size){
        return;
    }

    //processing
    maxNum=max(maxNum,arr[index]);

    //recursive call
    findMax(arr,size,index+1,maxNum);
}

int main(){
    int arr[] = {10,20,30,40,50};
    int index = 0;
    int size = 5;
    int maxNum = INT_MIN;

    findMax(arr,size,index,maxNum);
    cout<< maxNum << endl;
}