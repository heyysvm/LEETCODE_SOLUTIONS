class Solution {
public:
    int minimumDeletions(string s) {
        int bCount =0 , deletion =0;

        for(char c:s){
            if(c=='b') bCount++;
            else {
                deletion = min(deletion+1,bCount);
            }
        }
        return  deletion;
    }
};