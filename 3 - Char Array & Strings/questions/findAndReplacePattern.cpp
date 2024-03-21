// https://leetcode.com/problems/find-and-replace-pattern/
class Solution {
public:
    // Function to normalize a string based on character mapping
    void createMapping(string& str) {
        char mapping[300] = {0};
        char start = 'a';

        for (char& ch : str) {
            if (mapping[ch] == 0) {
                mapping[ch] = start;
                start++;
            }
            ch = mapping[ch];
        }
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        // Normalize the pattern
        createMapping(pattern);

        for (const string& s : words) {
            string tempString = s;
            // Normalize temp string
            createMapping(tempString);

            if (tempString == pattern) {
                // It means that "s" is a valid answer
                ans.push_back(s);
            }
        }
        return ans;
    }
};