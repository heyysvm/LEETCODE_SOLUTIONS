class Solution {
public:

 int start = 0 ; 
 int maxlen = 1; 

 void expand(string& s , int left , int right){
    while(left>=0 && right<=s.size() && s[left]==s[right]){
        if(right-left+1 > maxlen){
            maxlen = right-left+1;
            start = left;
        }
        left-- , right++;
    }
 }


//    bool isPalindrome(string ss){
    //     int left =0;
    //     int right = ss.size()-1;
    //     while(left<right){
    //         if(ss[left]!=ss[right])return false;
    //         left++ , right--;
    //     }
    //     return true;
    // }

    string longestPalindrome(string s) {
    //     string ans;
    //     for(int r=0;r<s.size();r++){
    //         for(int l=r;l<s.size();l++){
    //             string ss = s.substr(r,l-r+1);
    //               if(isPalindrome(ss)){
    //                 if(ss.size()>ans.size()){
    //                 ans = ss;
    //             }
    //         }
    //         }
            
    //     }
    //     return ans;

    for(int i=0;i<s.size();i++){
        expand(s,i,i);
        expand(s,i,i+1);
    }

    return s.substr(start,maxlen);
    }
};