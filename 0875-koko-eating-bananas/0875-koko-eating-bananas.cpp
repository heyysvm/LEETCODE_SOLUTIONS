class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
    int l = 1; 
    int r = *max_element(piles.begin(),piles.end());
    
    while(l<=r){
        long long totalHours = 0;
        int mid = l+(r-l)/2;
        for(int pile:piles){
            totalHours += ceil(double(pile)/mid);
        }
        if(totalHours<=h){
            r=mid-1;
        }
        else l= mid+1;
    }
    return l;
    }
};