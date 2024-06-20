// https://www.geeksforgeeks.org/problems/the-celebrity-problem/1
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> st;
        
        //step1: push all person
        for(int i = 0; i < n; i++){
            st.push(i);
        }
            // step2
            while(st.size() != 1){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                
                if(M[a][b]){
                    //a is not a celeb
                    st.push(b);
                    
                }else{
                    //b is not a celeb
                    st.push(a);
                }
            }
            
            //step3: single person in stack might be celebrity
        int mightBeCeleb = st.top(); st.pop();
        
        //check mightbe celeb is valid or not
        //celeb should not know anyone
        for(int i=0;i<n;i++){
            if(M[mightBeCeleb][i] != 0){
                return -1;
            }
        }
        
        //everyone should know celeb
        for(int i=0;i<n;i++){
            if(M[i][mightBeCeleb] == 0 && i != mightBeCeleb){
                return -1;
            }
        }
        
        return mightBeCeleb;
        
        
    }
};