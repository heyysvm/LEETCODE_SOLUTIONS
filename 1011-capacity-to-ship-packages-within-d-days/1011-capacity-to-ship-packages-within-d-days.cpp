class Solution {
public:

    int daysReq(vector<int>& weights, int capacity){
        int day =1;
        int curr = 0 ; 
        for(int weight : weights){
            if(curr + weight >capacity) {
                day++;
                curr = weight; 
            }
            else curr += weight;
        } return day;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        // for(int i= low; i<high ; i++){
        //     if ( daysReq(weights,i) <= days ) return i;
        // }
        // return high;

        while(low<=high){
            int mid= (low+high)/2;
            if(daysReq(weights,mid) <= days ) high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};