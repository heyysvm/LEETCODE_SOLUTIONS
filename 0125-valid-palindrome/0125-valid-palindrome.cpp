class Solution {
public:
    bool isPalindrome(string s) {
     string neww = "";
     
     for(char c:s){
        if(isalnum(c)){
            neww+=tolower(c);
        }
     }

     string rev = neww;
     reverse(rev.begin(),rev.end());
     return neww == rev;

    }
};