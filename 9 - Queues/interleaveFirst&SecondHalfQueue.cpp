// https://www.geeksforgeeks.org/problems/interleave-the-first-half-of-the-queue-with-second-half/1
class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &first){
        queue<int> second;
        vector<int>res;
        int n = first.size();
        
        for(int i=0;i<n/2;i++){
            int temp = first.front();
            first.pop();
            second.push(temp);
        }
        
        //merge
        for(int i=0;i<n/2;i++){
            int temp = second.front();
            second.pop();
            first.push(temp);
            
            int temp2 = first.front();
            first.pop();
            first.push(temp2);
        }
        
        while(!first.empty()){
            int temp = first.front();
            first.pop();
            res.push_back(temp);
        }
        return res;
    }
};