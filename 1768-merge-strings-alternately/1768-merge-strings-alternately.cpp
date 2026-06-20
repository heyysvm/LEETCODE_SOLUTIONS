class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int l=0,r=0;
        string ans="";
        while(l<word1.size() && r<word2.size()){
             ans+= word1[l++];
             ans+= word2[r++];
        }
        while(l<word1.size()) ans+=word1[l++];
        while(r<word2.size()) ans+=word2[r++];
        return ans;
    }
};