// https://leetcode.com/problems/reverse-vowels-of-a-string/submissions/1211805318/
class Solution {
public:

    bool isVowel(char ch){
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    string reverseVowels(string s) {
        int l=0;
        int h= s.size()-1;

        while(l<h){
            if(isVowel(s[l]) && isVowel(s[h])){
                swap(s[l], s[h]);
                l++;
                h--;
            }
            else if(!isVowel(s[l])){
                l++;
            }
            else{
                h--;
            }
        }
        return s;
    }
};