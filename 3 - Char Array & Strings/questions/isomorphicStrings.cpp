// https://leetcode.com/problems/isomorphic-strings/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int hash[256] = {0};  //hash table to store s
        bool istCharMapped[256] = {0}; //Kya t[i] mapped h s[i] se

        
        for(int i=0; i<s.size();i++){
            if(hash[s[i]] == 0 && istCharMapped[t[i]]==0){
                hash[s[i]] = t[i];
                istCharMapped[t[i]] = true;
            }
        }

        for(int i=0; i<s.size(); i++){
            if(char(hash[s[i]]) != t[i]){
                return false;
            }
        }
        return true;
    }
};