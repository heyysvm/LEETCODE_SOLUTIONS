class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
     int sum=0 , count =0;
     unordered_map<int,int> mp;
     mp[0]=1;  // set a prefix sum ie 0 seen 1 time
     for(int num:nums){
        sum+=num;
        if(mp.count(sum-k)){
            count+=mp[sum-k]; // each occN of sum-k forms a valid subarray
        }
        mp[sum]++;
     }return count;
    }
};