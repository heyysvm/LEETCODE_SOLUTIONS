class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int l= 0;
        unordered_map<int,int> freq;
        int maxs = 0;

        for(int r=0;r<n;r++){
            freq[nums[r]]++;
            while(freq[nums[r]]>k){
                freq[nums[l]]--;
                l++;
            }
            maxs = max(maxs,r-l+1);
        }
        return maxs;
    }
};