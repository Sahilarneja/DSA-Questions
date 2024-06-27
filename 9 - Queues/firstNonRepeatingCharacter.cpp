#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(){
    string str = "ababc";
    int freq[26] = {0}; 
    queue<char> q; 

    for(int i = 0; i < str.length(); i++){
        char ch = str[i];
        freq[ch - 'a']++;
        q.push(ch); 

        while(!q.empty()){
            char chFront = q.front();
            if(freq[chFront - 'a'] > 1){
                q.pop(); 
            } else {
                cout << chFront << "->";
                break;
            }
        }

        // If no non-repeating character is found
        if(q.empty()){
            cout << "#" << "->";
        }
    }

    return 0;
}
