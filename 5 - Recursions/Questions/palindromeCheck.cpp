#include <iostream>
using namespace std;

bool checkPalindrome(string &s, int start, int end ){
    if(start>=end){
        return true;
    }

    if(s[start] != s[end]){
        return false;
    }

    checkPalindrome(s, start+1, end-1);
}

int main(){
    string s = "arora";
    int start=0;
    int end= s.length()-1;
    checkPalindrome(s, start, end);
    if (checkPalindrome(s, start, end)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }
    return 0;
}