class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zero = 0; 
        int l =0 ; 
        int maxlen = 0 ; 
        for(int r=0; r<nums.size();r++){
            if(nums[r]==0) zero++;
            while(zero>1){
                if(nums[l]==0)zero--;
                l++;
            }
            maxlen = max(maxlen,r-l); // - because max widnow calc as if its contains a zero 
        }return maxlen;
    }
};