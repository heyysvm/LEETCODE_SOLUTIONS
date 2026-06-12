class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>freq;
        for(int x:nums){
            if(freq.find(x)!=freq.end())return true;
            freq.insert(x);
        }
        return false;
    }
};