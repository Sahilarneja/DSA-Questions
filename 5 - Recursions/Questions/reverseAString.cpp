#include <iostream>
using namespace std;

void reverse(string&s, int start, int end){
    //base case
    if(start>=end){
        return;
    }

    //processing
    swap(s[start], s[end]);

    //recursive call
    reverse(s, start+1, end-1);
}

int main(){
    string s = "abc";
    int start = 0;
    int end=s.size()-1;

    reverse(s, start, end);
    for(auto num:s){
        cout<< num<<" ";
    }
}