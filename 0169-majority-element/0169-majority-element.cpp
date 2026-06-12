class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int check = nums.size()/2;
        unordered_map<int,int> freq;
        for(int x:nums){
            freq[x]++;
            if(freq[x]>check)return x;
        }
         return -1;
    }
};