class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int prefs = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]-1 ==  nums[i-1]) prefs += nums[i];
            else break;
        }
        
        while(find(nums.begin(),nums.end(),prefs) != nums.end()) prefs++;
        return prefs;

    }
};