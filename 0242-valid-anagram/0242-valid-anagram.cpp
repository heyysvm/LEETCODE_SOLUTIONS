class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())return false;
         vector<int>freq(26,0);

         for(auto c:s){
            freq[c-'a']++;
         }
         for(auto c:t){
            freq[c-'a']--;
         }

        for(int i:freq){
            if(i)return false;
        }
        return true;

    }
};