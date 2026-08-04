class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        // int n = nums.size();
        // vector<int>ans;
        // sort(nums.begin(),nums.end());
        // for(int i=1;i<n;i++){
        //     for(int num=nums[i-1]+1;num<nums[i];num++){
        //         ans.push_back(num);
        //     }   
        // }
        // return ans;

        // unordered_set<int> st(nums.begin(),nums.end());
        // vector<int> ans;

        // int mins = *min_element(nums.begin(),nums.end());
        // int maxs = *max_element(nums.begin(),nums.end());

        // for(int x=mins+1; x<maxs; x++){
        //     if(!st.count(x)) ans.push_back(x);
        // }


        // return ans;

        vector<int>ans;
        vector<bool>isPresent(101,false);

        int mins = *min_element(nums.begin(),nums.end());
        int maxs = *max_element(nums.begin(),nums.end());
        for(int x:nums){
            isPresent[x]=true;
        }
        for(int x=mins+1;x<maxs;x++){
            if(isPresent[x]==false) ans.push_back(x);
        }
        return ans;

    }
};