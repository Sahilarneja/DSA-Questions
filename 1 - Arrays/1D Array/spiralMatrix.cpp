// https://leetcode.com/problems/spiral-matrix/

#include <vector>

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        std::vector<int> ans;
        int m = matrix.size();
        if (m == 0) return ans;  // Check for an empty matrix
        int n = matrix[0].size();
        int total_elements = m * n;

        int startingRow = 0;
        int endingCol = n - 1;
        int endingRow = m - 1;
        int startingCol = 0;

        int count = 0;

        while (count < total_elements) {
            // Print startingRow
            for (int i = startingCol; i <= endingCol && count < total_elements; i++) {
                ans.push_back(matrix[startingRow][i]);
                count++;
            }
            startingRow++;

            // Print endingRow
            for (int i = startingRow; i <= endingRow && count < total_elements; i++) {
                ans.push_back(matrix[i][endingCol]);
                count++;
            }
            endingCol--;

            // Print endingCol
            for (int i = endingCol; i >= startingCol && count < total_elements; i--) {
                ans.push_back(matrix[endingRow][i]);
                count++;
            }
            endingRow--;

            // Print startingCol
            for (int i = endingRow; i >= startingRow && count < total_elements; i--) {
                ans.push_back(matrix[i][startingCol]);
                count++;
            }
            startingCol++;
        }

        return ans;
    }
};
