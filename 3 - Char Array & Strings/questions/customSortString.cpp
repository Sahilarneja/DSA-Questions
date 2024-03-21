// https://leetcode.com/problems/custom-sort-string/
class Solution {
public:

    static string str;

    static bool compare(char char1, char char2){
        // return true if position of char1 is less than pos of char 2
        // if true, char1 will be placed before char2
        return (str.find(char1)<str.find(char2));
    }
    string customSortString(string order, string s) {
        str = order;

        sort(s.begin(), s.end(), compare);
        return s;
    }
};
string Solution::str;