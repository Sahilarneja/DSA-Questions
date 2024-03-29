#include <iostream>
using namespace std;

int main(){

    int a=10;

    //storing address of ptr
    int * ptr = &a;

    //Value of variable at ptr
    int val = *ptr;                      //derefrence operator- *


    cout<< a <<endl;
    cout<< "Address of a is: "<< ptr<<endl;
    cout <<"Value at Address: "<< &a <<" is: "<<  val;

}