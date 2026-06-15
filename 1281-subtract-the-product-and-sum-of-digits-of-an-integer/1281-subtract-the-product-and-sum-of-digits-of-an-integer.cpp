class Solution {
public:
    int subtractProductAndSum(int n) {
        int prod=1;
        int sum=0;
        while(n>0){
            int d = n%10;
            n/=10;
            sum+=d;
            prod*=d;
        }
        return  prod-sum;
    }
};