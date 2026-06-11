class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0;
        char temp ;
        int r = s.size()-1;
        while(l<r){
             temp = s[l];
            s[l]  = s[r];
            s[r] = temp;
            l++; 
            r--; 
        }
    }
};