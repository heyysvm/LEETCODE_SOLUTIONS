class Solution {
public:
    
    bool isVowel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }

    int maxVowels(string s, int k) {
         
        int vowel = 0 ;
        for(int i=0;i<k;i++){
            if(isVowel(s[i])) vowel++;
        }

        int ans =  vowel;  // initial vowel count is initial ans! 

        for(int r=k ; r<s.size();r++){ //  moving the window to right
            if(isVowel(s[r])) vowel++; // if next element to window is vowel then inc the v count
            if(isVowel(s[r-k])) vowel--; // if ele we removed from window is vowel then v count dec.
            ans = max(vowel,ans);
        }return ans;
    }
};