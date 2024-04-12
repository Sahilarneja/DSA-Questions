// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/1230113860/
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

int buyAndSell(vector <int> &nums, int minPrice, int maxProfit, int index){

    //base case
    if(index == nums.size()){
        return maxProfit;
    }

    //processing
    if(nums[index] < minPrice){
        minPrice = nums[index];  //sbse choti value/ min price store krli
    }
    int todaysPrice = nums[index] - minPrice;
    if(todaysPrice > maxProfit){
        maxProfit = todaysPrice;
    }

    //recursive call
    return buyAndSell(nums, minPrice, maxProfit, index+1);
}

int main(){
    vector <int> nums;
    int minPrice = INT_MAX;
    int maxProfit = INT_MIN;

    return buyAndSell(nums, minPrice, maxProfit, 0);
}