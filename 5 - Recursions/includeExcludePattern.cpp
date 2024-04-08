#include <iostream>
using namespace std;

void findSubstring(string str, string output, int index){
    //base case
    if(index >= str.length()){
        //ans bn chuka h 
        cout << output << endl;
        return;
    }

    char ch = str[index];

    //exclude 
    findSubstring(str, output, index+1);

    //include 
    output.push_back(ch);
    findSubstring(str, output, index+1);
}

int main(){
    string str = "abc";
    string output= "";
    int index = 0;

    findSubstring(str, output, index);
}