#include <iostream>
using namespace std;

bool search(int arr[][4], int row, int col, int target){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j] == target){
                return true;
            }
        }
    }
    return false; 
}

int main(){
    int arr[3][4] = {
    {1, 2, 3, 0},
    {4, 5, 6, 0},
    {7, 8, 9, 0}
};

int row = 3;
int col = 4;

    int target = 6;
    bool found = search(arr, row, col, target);
    cout<<found<<endl;

    return 0;
}