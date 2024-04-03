#include <iostream>
#include <climits> 
using namespace std;

void findMin(int arr[], int size, int index, int &mini) {
    // Base case
    if (index >= size) {
        return;
    }


    mini = min(mini, arr[index]);

    // Recursive call 
    findMin(arr, size, index + 1, mini);
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;
    int index = 0;
    int mini = INT_MAX; 

    
    findMin(arr, size, index, mini);

    
    cout << "Minimum element in the array is: " << mini << endl;

    return 0;
}
