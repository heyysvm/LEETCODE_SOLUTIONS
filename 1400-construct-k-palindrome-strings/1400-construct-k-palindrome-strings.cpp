class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size()<k)return false;
        if(s.size()==k)return true;
        vector<int> freq(26,0);
        int oddCount =0 ;

        for(char c:s){
            freq[c-'a']++;
        }
        for(int count : freq){
            if(count%2==1)oddCount++; // checking if any of count freq is odd 
        }
        return oddCount <= k;
    }
};