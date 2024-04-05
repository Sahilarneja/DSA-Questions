#include <iostream>
using namespace std;


void printDigits(int num){
    if(num == 0){
        return;
    }

    //processing
    int digits= num%10;
    //update
    num = num/10;

    //recursive call
    printDigits(num);

    cout<<digits<<" ";
}
int main(){
    int num= 4271;
    printDigits(num);
}