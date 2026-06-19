class Solution {
public:
    int trap(vector<int>& height) {
        int l=0 , r=height.size()-1 ; 
        int lmax = 0 , rmax = 0 ; 
        int water =0;
        
        while(l<r){
            if(height[l]<height[r]){
                if(height[l]>=lmax) lmax = height[l]; // next hig. wall 
                else water += lmax - height[l]; // lmax - bar height = water stored 
                l++;
            }
            else{
                if(height[r]>=rmax) rmax = height[r];
                else water += rmax - height[r];
                r--;
            }
        }
        return water;
    }
};