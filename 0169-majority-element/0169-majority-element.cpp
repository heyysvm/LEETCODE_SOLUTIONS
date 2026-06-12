class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // int check = nums.size()/2;
        // unordered_map<int,int> freq;
        // for(int x:nums){
        //     freq[x]++;
        //     if(freq[x]>check)return x;
        // }
        //  return -1;

        int cand= 0,count= 0 ;
        for(int num : nums){
            if(count==0 )cand=num;
            if(num==cand)count++;
            else count--;
        }return cand;
    }
};