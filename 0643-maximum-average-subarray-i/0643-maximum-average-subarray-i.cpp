class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int l = 0 , r = 0 ;

        // long long sum= 0 , maxs=0;
        long long sum =0;

        while(r<k){
            sum+=nums[r] , r++;
        } 

        long long maxs = sum;
        while(r<nums.size()){
            // maxs = max(maxs,sum);
            sum+=nums[r];
            sum-=nums[l];
            r++ ,l++;
            maxs = max(sum,maxs);
        }return double(maxs)/k;

    }
};