class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        for(int i =0; i<=n-m; i++){
            int j =0;
            while(j<m && haystack[i+j]==needle[j]){ // needle first ele is equals to haystack ith and ith+ jth ( as jth wrt needle )
                j++;
            }
            if(j==m)return i; // length of j equals to size of needle      
        }
        return -1;
    }
};