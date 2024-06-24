// https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/
class Solution {
public:
    bool isValid(string s) {
        if(s[0] != 'a'){
            return false;
        }

        stack<char> st;

        for(int i=0;i<s.size();i++){
            char c = s[i];

            if(c == 'a'){
                st.push(c);
            }else if( c == 'b'){
                if(!st.empty() && st.top()=='a'){
                    st.push(c);
                }else{
                    return false;
                }
            }
            else{
                //char c
                if(!st.empty() && st.top()=='b'){
                    st.pop();
                    if(!st.empty() && st.top()=='a'){
                        st.pop();
                    }else{
                        return false;
                    }
                }else{
                    return false;
                }
            }
        }
        return st.empty() ? true : false;
    }
};