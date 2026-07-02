class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int minp = prices[0];
        int  maxs=0;
        for(int p:prices){
            maxs = max(p-minp , maxs); // current minth and ith diff and maxes diff
            minp= min(p,minp);
        }return maxs;

        // for(int price:prices){
        //     minp = min(minp,price);
        //     maxs = max(price-minp , maxs);
        // }return maxs;
    }
};