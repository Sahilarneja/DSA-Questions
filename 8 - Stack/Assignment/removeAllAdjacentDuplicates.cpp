// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
class Solution {
public:
    string removeDuplicates(string s) {
        stack<int> st;

        for(int i=0;i<s.size();i++){
            char c = s[i];

            if(st.empty()){
                st.push(c);
            }else{
                if(st.top() == c){
                    st.pop();
                }else{
                    st.push(c);
                }
            }
        }
        string ans;
        while(!st.empty()){
            ans += st.top();
            st.pop();
           
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};