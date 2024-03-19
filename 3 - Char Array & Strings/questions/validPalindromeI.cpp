// https://leetcode.com/problems/valid-palindrome/submissions/1207891460/
class Solution {
public:
    bool isPalindrome(string s) {

        // Preprocess the string to remove non-alphanumeric characters and convert to lowercase
        string processedString;
        for (char c : s) {
            // isalnum function checks whether a character is alphanumeric
            if (isalnum(c)) {
                processedString += tolower(c);
            }
        }


        int i = 0;
        int j = processedString.length() - 1;

        while (i < j) {
            if (processedString[i] != processedString[j]) {
                return false;
            } else {
                i++;
                j--;
            }
        }
        return true;
    }
};