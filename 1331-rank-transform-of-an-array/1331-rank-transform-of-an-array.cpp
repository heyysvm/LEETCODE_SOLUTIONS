class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>sorted = arr;
        sort(sorted.begin(),sorted.end());
        unordered_map<int,int>hash;
        int r = 1;

        for(int x:sorted){
            if(!hash.count(x)){
                hash[x]=r++;
            }
        }

        for(int &x:arr){
            x = hash[x];
        }
        return arr;
    }
};