// https://leetcode.com/problems/combination-sum/
class Solution {
public:

    void combinationSumHelper(vector<int> &candidates, int target, vector<vector<int>> &ans, vector<int> &v, int index) {

        if(target == 0){
            ans.push_back(v);
            return;
        }

        if(target < 0){
            return;
        }

        for(int i=index;i<candidates.size(); i++){
            v.push_back(candidates[i]);
            combinationSumHelper(candidates, target-candidates[i], ans, v , i);
            v.pop_back();
        }


    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target, int index = 0) {
        vector<vector<int>> ans;
        vector<int> currentCombination;
        combinationSumHelper(candidates, target, ans, currentCombination, index);
        return ans;
    }
};