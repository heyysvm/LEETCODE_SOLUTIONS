class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {

        unordered_map <int,int>freq;

        for(int x:nums) freq[x]++; // count their frequency 
        vector<int>v;
        for(auto &p : freq) v.push_back(p.first);

        sort(v.begin(),v.end()); // sorting for matching the cond x<y;

        for(int i=0; i<v.size();i++){
            for(int  j=i+1;j<v.size();j++){
                if(freq[v[i]]!=freq[v[j]]) return {v[i],v[j]};  /// checking where frequency is not mathcing and smallest tho
            }
        }
        return {-1,-1};
    }
};