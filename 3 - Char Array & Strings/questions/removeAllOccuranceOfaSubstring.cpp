// https://leetcode.com/problems/remove-all-occurrences-of-a-substring/submissions/1207607466/
class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.find(part) != string::npos){
            //if inside loop, it means that part exists in a string
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};