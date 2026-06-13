class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i=m-1 ,  j = n-1 , k=m+n-1;
    
        while( i>=0 && j>=0){
            if(nums1[i]>nums2[j]) nums1[k]=nums1[i] , i-- , k--; // check individual of nums1 & nums2 and ini them with last index of nums1 ie initially zeroes
            else nums1[k]=nums2[j] , j-- , k--;
        }
        while(j>=0){   // for rest of the values if nums1 have more bigger ent than nums2
            nums1[k]=nums2[j] , j-- , k--;
        }
    }
};