// https://www.geeksforgeeks.org/problems/count-the-reversals0401/1
int countRev (string s)
{
    int ans = 0;
    stack<int> st;
    
    if(s.size() % 2 != 0){
        //means odd
        
        return -1;
    }
    
    for( int i=0;i<s.size();i++){
        char c = s[i];
        
        if(c == '{'){
            st.push(c);
        }else{
            if(!st.empty() && st.top() == '{'){
                st.pop();
            }else{
                st.push(c);
            }
        }
    }
    while(!st.empty()){
        char a = st.top(); st.pop();
        char b = st.top(); st.pop();
        
        if(a == b){
            ans += 1;
        }else{
            ans += 2;
        }
    }
    return ans;
}