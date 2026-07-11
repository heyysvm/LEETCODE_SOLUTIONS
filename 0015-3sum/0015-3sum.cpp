class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        // BRUTE FORCE -> 
        // set<vector<int>>st;
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         for(int k=j+1;k<n;k++){
        //             if(nums[i]+nums[j]+nums[k] == 0){
        //                 vector<int>temp = {nums[i],nums[j],nums[k]};
        //                 sort(temp.begin(),temp.end());
        //                 st.insert(temp);
        //             }
        //         }
        //     }
        // }
        // vector<vector<int>>ans(st.begin(),st.end());
        // return ans;

        // set<vector<int>>st;
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     set<int>hash;
        //     for(int j=i+1;j<n;j++){
        //         int third =  -(nums[i]+nums[j]);
        //         if(hash.find(third)!=hash.end()){
        //             vector<int>ans={nums[i],nums[j],third};
        //             sort(ans.begin(),ans.end());
        //             st.insert(ans);
        //         }
        //         hash.insert(nums[j]);
        //     }
        // }return vector<vector<int>>(st.begin(),st.end());

        // optimal sol ->

        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;

            int l = i+1 , r = n-1;

            while(l<r){
                int sum = nums[i] + nums[l]+nums[r];
                if(sum==0){
                    ans.push_back({nums[i],nums[l],nums[r]});
                    l++,r--;

                    while(l<r && nums[l]==nums[l-1]) l++;
                    while(l<r && nums[r]==nums[r+1]) r--;
                }
                else if(sum<0) l++;
                else r--;
            }
        }
            return ans;
    }
};