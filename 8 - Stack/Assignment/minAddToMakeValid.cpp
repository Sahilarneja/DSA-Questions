// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int ans = 0;

        for(int i=0;i<s.size();i++){
            char c = s[i];

            
                if(c == '('){
                    ans++;
                    st.push(c);
                }else{
                    if(!st.empty()){
                        ans--;
                        st.pop();
                    }else{
                        ans++;
                    }
                }
            
        }
        return ans;
    }
};