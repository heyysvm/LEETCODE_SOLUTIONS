class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int>freq(26,0);
        string left = "";
        string mid = ""; 

        for(char ch : s){
            freq[ch-'a']++;
        }
        for(int i=0;i<26;i++){
            if(freq[i]%2) mid = char('a'+i);
            left += string(freq[i]/2,char('a'+i)); 
        }
        string right = left;
        reverse(right.begin(),right.end());
        return (left+mid+right);
    }
};