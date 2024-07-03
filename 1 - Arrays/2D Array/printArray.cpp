#include<iostream>
using namespace std;


//row-wise print
void print(int (*arr)[4], int row, int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }
    }
}

//column-wise print
void colwise(int (*arr)[4], int row, int col){
    for(int j=0;j<col;j++){
        for(int i=0;i<row;i++){
            cout<<arr[i][j]<<" ";
        }
    }
}

int main(){
    int arr[3][4] = {
    {1, 2, 3, 0},
    {4, 5, 6, 0},
    {7, 8, 9, 0}
};

int row = 3;
int col = 4;

    // print(arr, row, col);
    colwise(arr, row, col);

    return 0;
}