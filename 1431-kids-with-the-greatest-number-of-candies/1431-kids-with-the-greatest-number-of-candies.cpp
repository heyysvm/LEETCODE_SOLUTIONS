class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxs = *max_element(candies.begin(),candies.end());
        vector<bool>ans;
        for(int cand : candies){
            ans.push_back(cand+extraCandies >= maxs);
        }return ans;
    }
};