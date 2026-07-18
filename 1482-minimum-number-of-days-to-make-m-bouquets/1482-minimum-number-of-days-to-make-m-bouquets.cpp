class Solution {
public:
    
    bool possible(vector<int>& bloomDay , int day , int m , int k ){
        int cnt = 0 , bouquets = 0 ; 
        for(int bloom : bloomDay){
             if(bloom <= day){
                cnt++;
                if(cnt==k){
                    bouquets++;
                    cnt =0;
                }
             }
                else cnt = 0;

        }
        return  bouquets >=  m;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long flowerNeeded = 1LL * m* k;
        int result = -1;
        if(flowerNeeded>bloomDay.size()) return -1;
        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        // for(int i= low;i<=high;i++){
        //     if(possible(bloomDay,i,m,k)) return i ;
        while(low<=high){
            int mid = (low+high)/2;
            if(possible(bloomDay,mid,m,k)){
                result = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return result;
    }
};