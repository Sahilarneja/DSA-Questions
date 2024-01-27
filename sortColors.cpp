class Solution {
public:
    void sortColors(vector<int>& nums) {
        //solution approach-3 in-place 3Pointer 
        int l=0;
        int m=0;
        int h=nums.size()-1;

        
        while(m<=h){
            if(nums[m]==0){
                swap(nums[l],nums[m]);
                l++,m++;
            }
            else if(nums[m]==1){
                m++;
            }else{
                swap(nums[m],nums[h]);
                h--;
            }
        }
    }

    // //approach-2 counting method
    // int zeroCount,oneCount,twoCount=0;
    // for(int i=0;i<nums.size();i++){
    //     if(nums[i]==0){
    //         zeroCount++;
    //     }else if(nums[i]==1){
    //         oneCount++;
    //     }else{
    //         twoCount++;
    //     }
    // }

    // //spread
    // int i=0;
    // while(zeroCount--){
    //     nums[i]=0;
    //     i++;
    // }
    // while(oneCount--){
    //     nums[i]=1;
    //     i++;
    // }
    // while(twoCount--){
    //     nums[i]=2;
    //     i++
    // }

    //approach-1 sorting
    // sort(nums.begin(),nums.end());

};