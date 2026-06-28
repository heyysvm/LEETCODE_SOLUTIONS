class Solution {
public:
    int maxArea(vector<int>& height) {
    int l = 0 , r = height.size()-1 , maxs = 0 ; 
    while(l<r){
        int area = min(height[l],height[r]) *( r-l);
        if(height[l]<height[r])l++;
        else r--;
        maxs = max(area,maxs);
    }return maxs;
    }
};