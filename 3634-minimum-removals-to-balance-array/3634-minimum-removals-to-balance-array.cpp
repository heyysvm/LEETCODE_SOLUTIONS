class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l=0 , longest=0 , n=nums.size();

        for(int r=0;r<n;r++){
            while((long long)nums[r]>(long long)nums[l]*k) l++;
            longest = max(longest, r-l+1);  // finding the lrgst win where r>= l*k
        }

        return n-longest;

    }
};