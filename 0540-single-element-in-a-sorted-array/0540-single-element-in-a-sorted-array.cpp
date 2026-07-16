class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // unordered_map<int,int>hash;
        // for(int x:nums){
        //     hash[x]++;
        // }
        // for(int x:nums){
        //     if(hash[x]==1) return x;
        // }
        // return -1;
        // int ans =0;
        // int n = nums.size()-1;
        // for(int num:nums){
        //     ans ^= num;
        // }
        // return ans;

    int n = nums.size()-1;
    if(nums.size()==1) return nums[0];
    if(nums[0]!=nums[1])return nums[0];
    if(nums[n]!=nums[n-1])return nums[n];

    int low = 1, high = n-1;
    while(low<=high){
        int mid = (low+high)/2;

        if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]) return nums[mid];
        if(mid%2==0 && nums[mid]==nums[mid+1] ||
           mid%2!=0 && nums[mid]==nums[mid-1] ) low = mid+1;
        else  high = mid-1;
    }
    return -1;

    }
};