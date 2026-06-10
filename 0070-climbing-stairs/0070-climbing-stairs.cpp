class Solution {
public:
    int climbStairs(int n) {
       if(n<=2) return n;
       int prev2 = 1; // 1 way for n1
       int prev1 = 2; // 2 waus for n2 

       for(int i=3;i<=n;i++){
        int curr = prev2 + prev1; // following fibonacci  series sequence 
        prev2 = prev1;
        prev1 = curr;
       } return prev1;
    }
};