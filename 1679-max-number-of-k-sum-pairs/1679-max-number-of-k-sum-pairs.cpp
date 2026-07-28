class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        // sort(nums.begin(),nums.end());
        // int l = 0 ; 
        // int r = nums.size()-1;
        // int opr  = 0 ;
        // while(l<r){
        //     int sum = nums[l]+nums[r];
        //     if(sum==k) opr++ , l++ , r--;
        //     else if(sum>k)r--;
        //     else l++;
        // }
        // return opr;
        int op=0;
        unordered_map<int,int>freq;
        for(int num:nums){
            int need = k-num;
            if(freq[need]>0){
                op++;
                freq[need]--;
            }
            else freq[num]++;
        }
        return op;
    }
};