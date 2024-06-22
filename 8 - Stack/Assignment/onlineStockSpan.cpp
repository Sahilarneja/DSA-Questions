// https://leetcode.com/problems/online-stock-span/submissions/1296275602/
class StockSpanner {
public:
    stack<pair<int,int>>st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;
        while(!st.empty() && st.top().first <= price){
            span += st.top().second;
            st.pop();
        };
        st.push({price, span});
        return span;
        
    }
};