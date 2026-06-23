class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int cur = 0 , mx =0;
        for(int i:gain){
            cur+=i;
            mx = max(mx,cur);
        }
        return mx;
    }
};