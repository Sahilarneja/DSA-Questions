#include <iostream>
using namespace std;


int factorial(int n){

    // base case 
    if(n == 1) return 1;

    if(n == 0) return 1;

    // recursive call
    int recursiveAns= factorial(n-1);

    int finalAns = n*recursiveAns;

    return finalAns;


}

int main(){
    int result = factorial(5);
    cout<<"Factorial of given no is: "<< result<<endl;
}