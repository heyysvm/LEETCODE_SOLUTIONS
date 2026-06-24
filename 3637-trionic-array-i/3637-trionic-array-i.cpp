class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int i=0;
        int n=nums.size()-1;
        int p1 = i;
        while(i<n && nums[i]<nums[i+1]) i++;
        if (p1==i) return false;
        int p2=i;
        while(i<n && nums[i]>nums[i+1]) i++;
        if(p2==i) return false;
        int p3 = i;
        while(i<n && nums[i]<nums[i+1]) i++;
        if(p3==i) return false;
        
        return i==n;
    } 
};