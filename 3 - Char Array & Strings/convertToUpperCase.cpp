#include <iostream>
using namespace std;

void convertToUpperCase(char ch[], int n) {
    int index = 0;

    // Loop through the array until index reaches n
    while (index < n) {
        char currCharacter = ch[index];

        // Check if lowercase then convert to uppercase
        if (currCharacter >= 'a' && currCharacter <= 'z') {
            ch[index] = currCharacter - 'a' + 'A';
        }

        // Move to the next character
        index++;
    }
}

int main(){
    char ch[100];

    cin.getline(ch, 100);
    
    cout<< "before: "<< ch<< endl;
    convertToUpperCase(ch,100);
    cout<<"after: "<<ch<<endl;
}