#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool redundant(string &str){
    stack<char> s;
    for(int i=0;i<str.length();i++){
        char ch = str[i];
        if(ch == '('){
            s.push(ch);
        }else{
            if(ch == ')'){
                int operatorCount = 0;
                while(!s.empty() && s.top() == '('){
                    char temp = s.top();
                    if(temp == '+' || temp == '-' || temp == '*' || temp == '/'){
                        operatorCount++;
                    }
                    s.pop();
                }
                s.pop(); //opening bracket
                if(operatorCount == 0){
                    return true;
                }   
            }
            else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            s.push(ch);
        }
        }
    }
    return false;

}


int main() {
    string str = "((a+b)*(c+d))";

    bool ans = redundant(str);
    if (ans == true) {
        cout << "The string does not have redundant parentheses." << endl;
    } else {
        cout << "The string have redundant parentheses." << endl;
    }
    return 0;
}