#include <iostream>
#include <vector>
using namespace std;

void storeDigits(int num, vector<int> &ans){
    if(num == 0){
        return;
    }

    int digits = num %10;
    ans.push_back(digits);

    //update
    num = num / 10;

    storeDigits(num, ans);

}

int main(){
    int num = 4327;
    vector<int>ans;
    storeDigits(num, ans);

    cout << "Digits of " << num << " are: ";
    for(int i = ans.size() - 1; i >= 0; i--){
        cout << ans[i] << " ";
    }
    cout << endl;

}