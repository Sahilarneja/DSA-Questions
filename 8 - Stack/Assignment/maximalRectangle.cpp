// https://leetcode.com/problems/maximal-rectangle/
class Solution {
public:
    vector<int> prevSmallest(vector<int>& heights, int n) {
        stack<int> st;
        vector<int> ans(n);

        st.push(-1);
        for(int i=0; i<n; i++) {
            int curr = heights[i];
            while(st.top() != -1 && heights[st.top()] >= curr) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> nextSmallest(vector<int>& heights, int n) {
        stack<int> st;
        vector<int> ans(n);

        st.push(-1);
        for(int i=n-1; i>=0; i--) {
            int curr = heights[i];
            while(st.top() != -1 && heights[st.top()] >= curr) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> right = nextSmallest(heights, n);
        vector<int> left = prevSmallest(heights, n);

        int maxi =0;
        for(int i=0;i<n;i++){
            if(right[i] == -1){
                right[i] = n;
            }

            int width = right[i] - left[i] -1;
            int area = heights[i] * width;
            maxi = max(area, maxi);
        }

        return maxi;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> v(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                v[i][j] = matrix[i][j] - '0';
            }
        }

        int area = largestRectangleArea(v[0]);
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(v[i][j]) {
                    v[i][j] += v[i-1][j];
                } else {
                    v[i][j] = 0;
                }
            }
            area = max(area, largestRectangleArea(v[i]));
        }

        return area;
    }
};