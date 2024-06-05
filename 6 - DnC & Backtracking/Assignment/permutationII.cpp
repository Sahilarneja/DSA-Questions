// https://leetcode.com/problems/permutations-ii/
class Solution {
public:

    void permutationUniqueHelper(vector<int>& nums, vector<vector<int>> &ans, int start){
        unordered_map<int,bool>visited;
        if(start == nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i=start;i<nums.size();i++){
            if(visited.find(nums[i]) != visited.end()){
                continue;
            }
            visited[nums[i]] == true;
            swap(nums[i], nums[start]);
            permutationUniqueHelper(nums, ans, start+1);
            swap(nums[i], nums[start]);
        }

        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        permutationUniqueHelper(nums, ans, 0);

        // set<vector<int>> st;
        // for (const auto& e : ans) {
        //     st.insert(e);
        // }
        // ans.clear();

        // for (const auto& e : st) {
        //     ans.push_back(e);
        // }

        return ans;
    }
};