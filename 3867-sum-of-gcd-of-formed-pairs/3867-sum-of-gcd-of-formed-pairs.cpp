class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int>prefixGcd;
        int mx = 0;
        for(int num:nums){
            mx = max(mx,num);
            prefixGcd.push_back(gcd(mx,num));
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        long long ans = 0;

        int l =0 , r = nums.size()-1;

        while(l<r){
            ans+= gcd(prefixGcd[l],prefixGcd[r]);
            l++ , r--;
        }
        return ans;
    }
};