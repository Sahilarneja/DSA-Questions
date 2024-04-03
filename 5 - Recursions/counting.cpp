#include <iostream>
using namespace std;


void printCounting(int n){
    if(n==1){
        cout<<1;
        return;
    }

    cout << n << " ";
    printCounting(n-1);
}

int main(){
    printCounting(10);
}