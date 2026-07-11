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

        // int n = nums.size();
        // set<vector<int>>st;

        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         unordered_set<int>hash;
        //         for(int k=j+1;k<n;k++){
        //             long long required = 1LL * target - nums[i] - nums[j] - nums[k];
        //             if( required >= INT_MIN && required <= INT_MAX && hash.find((int)required)!=hash.end()){
        //                 vector<int>temp={nums[i],nums[j],nums[k],int(required)};
        //                 sort(temp.begin(),temp.end());
        //                 st.insert(temp);
        //             }
        //             hash.insert(nums[k]);
        //         }
        //     }
        // }
        // return vector<vector<int>>(st.begin(),st.end());

        int n = nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n;j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                
                int l = j+1 , r= n-1;
                while(l<r){
                    long long sum = 1LL * nums[i] + nums[j] + nums[l] + nums[r];
                    if(sum==target){
                        ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                        l++ , r--;
                        while(l<r && nums[l]==nums[l-1])l++;
                        while(l<r && nums[r]==nums[r+1])r--;
                    }
                    else if(sum<target) l++;
                    else r--;
                }
            }
        }
    return ans;
    }
};