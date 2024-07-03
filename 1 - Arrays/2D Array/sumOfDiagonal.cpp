#include <iostream>
using namespace std;


int sumOfDiagonal(int arr[][4], int row, int col){
    int sum = 0;
    for(int i = 0; i < row; i++){
        sum += arr[i][i];
    }
    return sum;
}

int main(){
        int arr[3][4] = {
    {1, 2, 3, 0},
    {4, 5, 6, 0},
    {7, 8, 9, 0}
};

int row = 3;
int col = 4;

int res = sumOfDiagonal(arr, row,col);
cout<< res<<endl;
}