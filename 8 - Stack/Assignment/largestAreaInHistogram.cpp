// https://leetcode.com/problems/largest-rectangle-in-histogram/description/
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
};