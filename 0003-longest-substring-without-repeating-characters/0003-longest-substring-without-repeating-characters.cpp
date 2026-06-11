class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int l = 0 , r = 0 , maxlen = 0 , n = s.size();
       vector <int> freq(256,-1);

       while(r<n){
        if(freq[s[r]]!=-1){ // if character is present hash array ?? 
            if(freq[s[r]]>=l){ // is that character present in current window ? 
                l = freq[s[r]]+1; // move left pointer to +1 of that character
            }
        }
        int len = r-l+1; // new len always calc at every iteration 
        maxlen = max(len , maxlen);
        freq[s[r]]=r; //  index for the character of rth
        r++;
       }return maxlen;
    }
};