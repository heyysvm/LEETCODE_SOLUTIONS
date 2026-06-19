class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l =0;
        int r = nums.size()-1;
        int operations = 0 ;
        while(l<r){
            if(nums[l]+nums[r]==k) operations++ , l++ , r--;
            else if(nums[l]+nums[r] < k)l++;
            else r--;
        }
        return operations;
    }
};