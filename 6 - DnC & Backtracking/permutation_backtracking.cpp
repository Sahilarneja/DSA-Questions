#include <iostream>
using namespace std;

void solve(string &s, int index){

    //base case
    if(index >= s.length()){
        return;
    }

    //processing
    for(int j=index ; j<s.length();j++){
        swap(s[index], s[j]);
        cout << s << " ";

        //recursive call
        solve(s, index+1);

        //backtracking
        swap(s[index], s[j]);
    }
}

int main(){
    string s = "abc";
    int index = 0;
    solve(s, index);
}
