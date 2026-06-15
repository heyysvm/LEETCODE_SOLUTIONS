class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>result;
        int csum =0;
        for(int i=0;i<nums.size();i++){
            csum+=nums[i];
            result.push_back(csum);
        }return result;
    }
};