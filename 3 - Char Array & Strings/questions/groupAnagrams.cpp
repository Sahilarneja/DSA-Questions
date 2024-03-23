// https://leetcode.com/problems/group-anagrams/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map <string , vector<string>> mp;

        for(auto str: strs){
            string s = str;
            sort(s.begin(), s.end());
            mp[s].push_back(str);  //s will be key and str will be value
        }

    vector<vector<string>> ans;
    for(auto it=mp.begin(); it!=mp.end(); it++){
        ans.push_back(it -> second);   //key -> first && value -> second in map
    }
    return ans;
    }
};