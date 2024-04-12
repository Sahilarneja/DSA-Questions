#include <iostream>
#include <vector>
using namespace std;

void printSubArray (vector<int>&v, int start, int end){

    //base case
    if(start > end || end == v.size()){
        return;
    }
    //processing
    for(int i=start; i<=end; i++){
        cout<< v[i] << " ";
    }
    cout<< endl;

    //recursive call
    printSubArray(v, start, end+1);

}

int printSubArrayIncrement(vector<int>&v){

    for(int start = 0; start < v.size(); start++){
        int end = start;
        printSubArray(v, start, end);
    }
}

int main(){
    vector<int> v{1,2,3,4,5};
    int start = 0;
    int end = start;
    printSubArrayIncrement(v);

}