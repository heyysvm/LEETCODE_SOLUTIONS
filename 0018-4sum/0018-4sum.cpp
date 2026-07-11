class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // brute force -> 

        // int n = nums.size();
        // set<vector<int>>st;  

        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         for(int k=j+1;k<n;k++){
        //             for(int l=k+1;l<n;l++){
        //                 long long sum = nums[i] + nums[j] + nums[k] + nums[l];
        //                 if(sum==target){
        //                     vector<int>temp={nums[i],nums[j],nums[k],nums[l]};
        //                     sort(temp.begin(),temp.end());
        //                     st.insert(temp);
        //                 }
        //             }
        //         }
        //     }
        // }
        // return vector<vector<int>>(st.begin(),st.end());

        int n = nums.size();
        set<vector<int>>st;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                unordered_set<int>hash;
                for(int k=j+1;k<n;k++){
                    long long required = 1LL * target - nums[i] - nums[j] - nums[k];
                    if( required >= INT_MIN && required <= INT_MAX && hash.find((int)required)!=hash.end()){
                        vector<int>temp={nums[i],nums[j],nums[k],int(required)};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                    hash.insert(nums[k]);
                }
            }
        }
        return vector<vector<int>>(st.begin(),st.end());
    }
};