class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxs = INT_MIN; //  must be min int val
        int sum =0;
        // int start = 0;
        // int st = -1 , end = -1;  //for printing the subarray

        for(int i=0;i<nums.size();i++){

            // if(sum==0)start=i;

            sum+=nums[i];

            // if(sum>maxs){
            //     maxs = sum;
            //     st =start;
            //     end =i;      // st---end => subarray
            // }

            maxs = max(sum,maxs);
            if(sum<0)sum=0;
        }return maxs;
    }
};