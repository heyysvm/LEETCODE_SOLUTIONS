class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0 , ans = 0 , zeros = 0 ; 
        // we will make a window valid only when zero is <= K if it greater than k than we will slide the window and check whether left part have zero or not if have zero than dec the zeros and move ahead !
        for(int r=0 ; r<nums.size();r++){

            if(nums[r]==0)zeros++; // count zeros

            while(zeros>k){  //  zero go beyond k 

                if(nums[l]==0)zeros--; // then shrink the window from left && a zero left the window so we dec the zero count
                l++; // left move ahead
            }
            ans = max(ans,r-l+1);  // no of all one and k'0 is within the window so max len of window is ans ! 
        }return ans;
    }
};