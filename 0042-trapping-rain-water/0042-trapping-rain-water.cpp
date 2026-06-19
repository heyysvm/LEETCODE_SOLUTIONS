class Solution {
public:
    int trap(vector<int>& height) {
        int l =0;
        int r= height.size()-1;
        int leftMx = 0;
        int rightMx = 0;
        int water = 0 ;
    
        while(l<r){
            if(height[l]<height[r]){
                if(height[l]>=leftMx) leftMx = height[l];
                else water+= leftMx -height[l];
                l++;
            }
            else{
                if(height[r]>=rightMx) rightMx = height[r];\
                else water+= rightMx -height[r];
                r--;
            }
            
        }return water;
    }
};