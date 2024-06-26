// https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1
class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        stack<int>st;
        int n = q.size();
        
        if(k == 0 || k>n){
            return q;
        }
        
        for(int i=0;i<k;i++){
            int temp = q.front();
            q.pop();
            st.push(temp);
        }
        
        while(!st.empty()){
            int ans = st.top();
            st.pop();
            q.push(ans);
        }
        
        for(int i=0;i<(n-k);i++){
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
        return q;
    }
};
