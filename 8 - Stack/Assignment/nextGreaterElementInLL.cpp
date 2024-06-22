// https://leetcode.com/problems/next-greater-node-in-linked-list/submissions/1296255249/
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ll;
        while(head != NULL){
            ll.push_back(head->val);
            head = head->next;
        }

        vector<int> ans(ll.size(), 0);
        stack<int> st;
        
        for(int i=0;i<ll.size();i++){
            while(!st.empty() && ll[st.top()]<ll[i]){
                int kids = st.top();
                st.pop();
                ans[kids] = ll[i];
            }
            st.push(i);
        }
        return ans;
    }
};