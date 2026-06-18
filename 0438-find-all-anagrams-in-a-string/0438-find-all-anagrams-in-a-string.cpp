class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        if(p.size()>s.size())return ans;

        vector<int>freqs(26,0);
        vector<int>freqp(26,0);

        for(char c:p)freqp[c-'a']++;
        for(int i=0;i<p.size();i++) freqs[s[i]-'a']++;

        if(freqs==freqp) ans.push_back(0);

        for(int i=p.size();i<s.size();i++){
            freqs[s[i]-'a']++;
            freqs[s[i-p.size()]-'a']--;
            if(freqs==freqp) ans.push_back(i-p.size()+1);
        }
        return ans;
    }
};