#include <iostream>
using namespace std;

int sum(int arr[][4], int row, int col){
    int sum = 0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            sum = sum+arr[i][j];
        }
    }
    return sum;
}

int main()
{
    int arr[3][4] = {
        {1, 2, 3, 0},
        {4, 5, 6, 0},
        {7, 8, 9, 0}};

    int row = 3;
    int col = 4;

    int ans = sum(arr, row, col);
    cout << "Sum of all elements in the array: " << ans << endl;

    return 0;
}