class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // int maxs = INT_MIN;
        // for(int i =0;i<nums.size();i++){
        //     int prod=1;
        //     for(int j=i;j<nums.size();j++){
        //         prod *= nums[j];
        //         maxs = max(prod,maxs);
        //     }
        // }
        // return maxs;
        
        int pre = 1; 
        int suf = 1;
        int ans = INT_MIN;
        int n = nums.size();

        for(int i=0;i<n;i++){
            if(pre==0) pre=1;
            if(suf==0) suf=1;

            pre *= nums[i];
            suf *= nums[n-1-i];

            ans =   max(ans,max(pre,suf));
        }
        return ans;
    }
};