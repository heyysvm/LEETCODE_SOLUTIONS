class Solution {
public:
    int maxDepth(string s) {
       int maxs =0 , cnt =0 ;
       for(char ch:s){
        if(ch=='(') cnt++;
        if(ch==')')cnt--;
        maxs= max(maxs,cnt);
       }
       return maxs;
    }
};