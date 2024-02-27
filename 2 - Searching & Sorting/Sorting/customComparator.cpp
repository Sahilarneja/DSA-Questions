#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool myComp(int &a, int &b){
    // return a<b; //increasing
    return a>b; // decreasing
}

int main(){
    vector<int> v={44,55,22,11,33};
    // sort(v.begin(),v.end());  //in increasing order
    sort(v.begin(), v.end(), myComp);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}