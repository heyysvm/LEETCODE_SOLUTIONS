class Solution {
public:

    int countSubarrays(vector<int>& nums,int maxSum){
        int noOfSubarrays =1;
        int currSum = 0;

        for(int num:nums){
            if(currSum+num <= maxSum) currSum+=num;
            else {
                noOfSubarrays++;
                currSum = num;
            }
        }
        return noOfSubarrays;
    }

    int splitArray(vector<int>& nums, int k) {
        int low =  *max_element(nums.begin(),nums.end());
        int high =  accumulate(nums.begin(),nums.end(),0);

        // for(int i=low;i<=high;i++){
        //     if(countSubarrays(nums,i)<=k) return i;
        // }
        // return -1;

        while(low<=high){
            int mid = (low+high)/2;
            int subarrays = countSubarrays(nums,mid);
            if(subarrays > k) low =mid+1;
            else high = mid-1;
        }
        return low;
    }
};