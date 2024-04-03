#include <iostream>
using namespace std;


int sum(int n){
    //base case
    if(n == 1){
        return 1;
    }

    //recursive case
    int ans = n + sum(n-1);

    return ans;
}

int main(){
    int result = sum(5);
    cout << result << endl;
}