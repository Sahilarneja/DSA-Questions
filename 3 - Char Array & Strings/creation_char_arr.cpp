#include <iostream>
#include <cstring>
#include <algorithm> 
using namespace std;

int main() {
    //initialize
    char arr[10];

    //input
    // cin >> arr;

    // Null-terminate the string
    // arr[5] = '\0';

    //print
    // cout << "Printing the Char Array: " << arr << endl;

    //length of string 
    // cout<< strlen(arr)<<endl;

    //or using forLoop
    // int length=0;
    // for(int i=0;i<10;i++){
    //     if(arr[i]=='\0'){
    //         break;
    //     }else{
    //         length++;
    //     }
    // }

    // cout<< "Length using for loop: "<< length;

    //Reverse a string
      // Swap elements from the beginning to the end of the array
    // while (i < j) {
    //     // Swap arr[i] and arr[j]
    //     swap(arr[i], arr[j]);
        
    //     // Move to the next pair of elements
    //     i++;
    //     j--;
    // }

    // // Print the reversed array
    // cout << "Reversed Char Array: " << arr << endl;

    //to get complete line
    cin.getline(arr, 10);
    
    // cout<< strlen(arr);
}

//Access ---- ch[index]

