// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/submissions/1214357659/
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        for(int i=0; i<=n-m; i++){
            for(int j=0; j<m; j++){
                if(needle[j] != haystack[i+j]){
                    break;
                }
                if(j == m - 1){
                    return i;
                }
            }
        }
        return -1;        
    }
};


// 1) n - m in the outer loop:
// We use n - m as the upper bound for the outer loop to ensure that there are enough characters left in haystack to accommodate the entire needle.
// If haystack is smaller than needle, there's no need to continue searching since it's impossible for needle to exist in haystack in such cases.
// By using n - m, we limit the iterations of the outer loop to only those positions in haystack where it's possible for needle to exist.
// m - 1 in the inner loop:

// 2) We use m - 1 as the condition in the inner loop because we want to compare characters of haystack with characters of needle up to the second-last character of needle.
// This is because when we reach the position j = m - 1, we will compare the last character of needle with the character in haystack at position i + j.
// If all characters of needle match with the characters in haystack starting from index i, then j will reach m - 1, indicating that we have found a match for needle in haystack.