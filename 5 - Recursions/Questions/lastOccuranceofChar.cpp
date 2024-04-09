# include <iostream>
using namespace std;

int lastOccur(string&s, char x, int i, int&ans){

    //base case
    if(i>=s.size()){
        return ans;
    }

    //processing
    if(s[i] == x){
        ans = i;
    }

    return lastOccur(s, x, i+1, ans);
}

int main() {
    string s = "abcddedg";
    int i = 0;
    char x = 'd';
    int ans = -1; 

    cout << "Last occurrence of '" << x << "' is at index: " << lastOccur(s, x, i, ans) << endl;

    return 0;
}