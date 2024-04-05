#include <iostream>
using namespace std;

int findTarget(int arr[], int size, int index, int target, int count){

    if(index>=size){
        return count;
    }

    if(arr[index]==target){
        count++;
    }

    return findTarget(arr, size, index+1, target, count);

}

int main(){
    int arr[] = {10, 20, 10, 40, 10, 50};
    int size = 6;
    int index = 0;
    int target = 10;
    int count = 0;

    int result=findTarget(arr, size, index, target, count);
    cout<<result<<endl;
}