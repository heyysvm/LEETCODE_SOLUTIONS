class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>freq;
        for(int x:arr) freq[x]++;
        unordered_set<int>st;
        for(auto x:freq){
            if(st.count(x.second)) return false;
            st.insert(x.second);
        }
        return true;
    }
};