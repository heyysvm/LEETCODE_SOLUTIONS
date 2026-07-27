class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // int maxs=INT_MIN;
        // for(int i=0;i<nums.size();i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         int prod = (nums[i]-1)*(nums[j]-1);
        //         maxs = max(prod,maxs);
        //     }
        // }
        // return maxs;
        // int n = nums.size();
        // sort(nums.begin(),nums.end());
        // return((nums[n-1]-1)*(nums[n-2]-1));

        int ele1 = INT_MIN;
        int ele2 = INT_MIN;

        for(int num:nums){
            if(num>ele1){
                ele2 = ele1;
                ele1 = num;
            }
            else if(num>ele2) ele2 = num;
        }
        return((ele1-1) * (ele2-1));


    }
};