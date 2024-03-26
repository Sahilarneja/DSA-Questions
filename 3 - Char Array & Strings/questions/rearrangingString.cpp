// https://leetcode.com/problems/reorganize-string/submissions/1214345810/
class Solution {
public:
    string reorganizeString(string s) {
        int hash[256] = {0};

        for(int i = 0; i < s.size(); i++) {
            hash[s[i] - 'a']++;
        }

        // Find most frequent character
        char most_freq_char;
        int max_freq = INT_MIN;
        for(int i = 0; i < 26; i++) {
            if(hash[i] > max_freq) {
                max_freq = hash[i];
                most_freq_char = i + 'a';
            }
        }

        int index = 0;
        // Place most frequent character at every other position
        while(max_freq > 0 && index < s.size()) {
            s[index] = most_freq_char;
            max_freq--;
            index += 2;
        }

        if(max_freq != 0) {
            return ""; // Impossible to rearrange string
        }

        hash[most_freq_char - 'a'] = 0;

        // Place the rest of the characters
        for(int i = 0; i < 26; i++) {
            while(hash[i] > 0) {
                index = index >= s.size() ? 1 : index; // Corrected
                s[index] = i + 'a';
                hash[i]--;
                index += 2;
            }
        }
        return s;
    }
};