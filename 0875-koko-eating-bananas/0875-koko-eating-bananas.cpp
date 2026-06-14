class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1; 
        int r = *max_element(piles.begin(),piles.end());

        while(l<r){
            int mid = l + (r-l)/2;
            long long hrs = 0 ;
            for(int pile :piles){
                hrs += (pile+mid-1)/mid;
                // hrs += (ceil(double(pile)/mid));
            }
            if(hrs<=h)r=mid; //smaller value may exist 
            else l=mid+1;
        }return l;
    }
};