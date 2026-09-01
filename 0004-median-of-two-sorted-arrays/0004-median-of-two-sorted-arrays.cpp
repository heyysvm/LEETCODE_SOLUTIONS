class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        // vector<int>nums3;
        // int n1  = nums1.size();
        // int  n2 = nums2.size();

        // int i =0 ,  j =0;

        // while(i<n1 && j<n2){
        //     if(nums1[i]<nums2[j]) nums3.push_back(nums1[i++]);
        //     else nums3.push_back(nums2[j++]);
        // }
        // while(i<n1) nums3.push_back(nums1[i++]);
        // while(j<n2) nums3.push_back(nums2[j++]);

        // int  n =  n1+n2;
        // if(n%2==1) return nums3[n/2];
        // return (nums3[n/2]+nums3[n/2-1])/2.0;


        int  n1 = nums1.size();
        int  n2 = nums2.size();
        int  indel1  =  -1 , indel2 = -1;
        int n = n1+n2;
        int idx2 =  n/2;
        int idx1 =  idx2-1;
        int cnt =0;
        int i=0,j=0;

        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]){
                if(cnt == idx2) indel2 = nums1[i];
                if(cnt == idx1) indel1 = nums1[i];
                cnt++;
                i++;
            }
            else{
                if(cnt ==  idx2) indel2 = nums2[j];
                if(cnt ==  idx1) indel1 = nums2[j];
                cnt++;
                j++;
            }
        }

        while(i<n1){
                if(cnt == idx2) indel2 = nums1[i];
                if(cnt == idx1) indel1 = nums1[i];
                cnt++;
                i++;
        }
        while(j<n2){
                if(cnt ==  idx2) indel2 = nums2[j];
                if(cnt ==  idx1) indel1 = nums2[j];
                cnt++;
                j++;
        }

    if(n%2==1)  return indel2;
    return (indel2 + indel1)/2.0; 
    }
};