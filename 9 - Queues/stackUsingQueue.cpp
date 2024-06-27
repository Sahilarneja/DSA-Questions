class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        //reverse
        for(int i=0;i<q.size()-1;i++){
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
    }
    
    int pop() {
        int top = q.front();
        q.pop();
        return top;
    }
    
    int top() {
        int top = q.front();
        return top;
    }
    
    bool empty() {
        return q.empty();
    }
};