// https://leetcode.com/problems/transpose-matrix/submissions/1307737993/
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> res(col, vector<int>(row));        
        

          for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                res[j][i] = matrix[i][j]; //in-place we just swap matrix[i][j], matrix[j][i]
            }
        }
        
        return res;

    }
};