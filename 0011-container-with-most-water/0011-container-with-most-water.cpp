class Solution {
public:
    int maxArea(vector<int>& height) {
    int l = 0 , r = height.size()-1 , maxs = 0 ; 
    while(l<r){
        int width = r-l ;
        int  ht = min(height[l],height[r]); 
        int area = width*ht;
        if(height[l]<height[r]){
            l++;
        }
        else r--;
        maxs = max(area,maxs);
    }return maxs;
    }
};