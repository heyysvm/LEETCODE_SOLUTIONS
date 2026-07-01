class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l=0 , maxs =1 ;
        long long total =0;
        for(int r=0;r<nums.size();r++){
            total += nums[r];

            // largest element of currect win * current windo len - totalsum > k 
            while((long long)nums[r] * (r-l+1) - total > k ){  // when currecnt win of inc the k(given op) shring from l 
                total -= nums[l];
                l++;
            }
            maxs = max(maxs,r-l+1);
        }
        return maxs;
    }
};

