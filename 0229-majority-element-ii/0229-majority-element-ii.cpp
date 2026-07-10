class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        // vector<int>ans;
        // unordered_map<int,int>hash;
        // int minVal = n/3 +1;
        // for(int i=0;i<n;i++){
        //     hash[nums[i]]++;          
        //     // for(int j=0;j<n;j++){
        //     //     if(nums[j]==nums[i]) count++;
        //     // }
        //     if(hash[nums[i]] == minVal) ans.push_back(nums[i]);
        //     if(ans.size()==2) break;
        // }
        // return ans;

        int cnt1 = 0 , cnt2=0;
        int ele1 = INT_MIN , ele2 = INT_MIN;

        for(int num:nums){
            if(num==ele1) cnt1++;
            else if (num==ele2) cnt2++;
            else if (cnt1==0){
                ele1 = num;
                cnt1 =1;
            } 
            else if (cnt2==0){
                ele2 = num;
                cnt2 = 1; 
            } 
            else cnt1-- , cnt2--;
        } 
        cnt1 = cnt2 = 0;
        vector<int>ans;
        for(int num:nums){
            if(num==ele1)cnt1++;
            else if(num==ele2)cnt2++; }
        int min = n/3;
        if(cnt1 > min) ans.push_back(ele1);
        if(cnt2 > min) ans.push_back(ele2);
        return ans;
            }
};