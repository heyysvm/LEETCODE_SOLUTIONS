class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l=0 , ans =0 , prod=1;
        if(k<=1)return 0;
        for(int r=0;r<nums.size();r++){
            prod*=nums[r];

            while(prod>=k){
                prod /= nums[l];
                l++;
            }
            ans+= (r-l+1);
        }return ans;
    }
};