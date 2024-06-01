// https://leetcode.com/problems/combination-sum-ii/submissions/1273893232/
class Solution {
public:
    void combinationSumHelper(vector<int> &candidates, int target, vector<vector<int>> &ans, vector<int> &currentCombination, int index) {
        if (target == 0) {
            ans.push_back(currentCombination);
            return;
        }

        if (target < 0) {
            return;
        }

        for (int i = index; i < candidates.size(); ++i) {
            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }
            currentCombination.push_back(candidates[i]);
            combinationSumHelper(candidates, target - candidates[i], ans, currentCombination, i+1);  
            currentCombination.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> currentCombination;
        combinationSumHelper(candidates, target, ans, currentCombination, 0);
        return ans;
    }
};
