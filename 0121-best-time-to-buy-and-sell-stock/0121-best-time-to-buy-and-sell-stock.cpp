class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minp = prices[0];
        int  maxs=0;
        for(int i=1;i<prices.size();i++){
            maxs = max(prices[i]-minp , maxs); // current minth and ith diff and maxes diff
            minp= min(prices[i],minp);
        }return maxs;
    }
};