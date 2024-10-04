// https://leetcode.com/problems/path-sum-ii/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, int targetSum, vector<int> temp,
               vector<vector<int>>& ans, int sum) {
                if(root == NULL){
                    return;
                }
                sum += root->val;
                temp.push_back(root->val);
                if(root->left == NULL && root->right == NULL){
                    if(sum == targetSum){
                        ans.push_back(temp);
                    }else{
                        return;
                    }
                }
                solve(root->left, targetSum, temp, ans, sum);
                solve(root->right, targetSum, temp, ans, sum);
               }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
         vector<int> temp;
        vector<vector<int>> ans;
        int sum = 0;
        solve(root, targetSum, temp, ans, sum);
        return ans;
    }
};