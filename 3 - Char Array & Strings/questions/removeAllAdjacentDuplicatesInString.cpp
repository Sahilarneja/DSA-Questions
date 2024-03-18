// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/submissions/1207599705/

class Solution {
public:
    string removeDuplicates(string s) {
        string ans="";
        int index=0;

        while(index < s.length()){
            //same
            //ans ka rightmost character and string s ka current character
            if (!ans.empty() && ans.back() == s[index]) {
                ans.pop_back();
            }else{
                //push
                ans.push_back(s[index]);
            }
            index++;
        }
        return ans;
    }
};