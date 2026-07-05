class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> st(nums.begin(),nums.end());
        int maxs =0;
        for(int num:st){
            if(st.find(num-1)==st.end()){
                int cur = num;
                int len =1;

                while(st.count(cur+1)){
                    cur++;
                    len++;
                }
                maxs = max(len,maxs);
            }
        }
            return maxs;

    }
};