#include <iostream>
using namespace std;

bool checkPalindrome(char ch[], int n){
    int i=0;
    int j=n-1;

    while(i <= j){
        if(ch[i]==ch[j]){
            i++;
            j--;
        }else{
            return false;
        }
    }
    return true;
}

int main(){

    char ch[100];

    cin.getline(ch, 100);

    int length = 0;
    while(ch[length] != '\0'){
        length++;
    }

    bool isPalindrome = checkPalindrome(ch, length);

    if(isPalindrome){
        cout << "Palindrome" << endl;
    } else {
        cout << "Not a palindrome" << endl;
    }

    return 0;
}
