class Solution {
public:

    int sumD( vector<int>& nums, int d){
        int sum =0;
        for(int num:nums){
        sum += ceil(double(num)/d);
        }
        return sum; 
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        // int n = nums.size();
        // for(int div = 1; div<=high;div++){
        //     int sum = 0; 
        //     for(int i=0;i<n;i++){
        //         sum += ceil((double)nums[i]/(double)div);
        //     }
        //     if(sum<=threshold) return div;
        // }
        // return -1;

        if(nums.size() > threshold)return-1;
        int low = 1; 
        int high = *max_element(nums.begin(),nums.end());

        while(low<=high){
            int mid = (low+high)/2;
            if(sumD(nums,mid) <= threshold) high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};