class Solution {
public:
    long long sumAndMultiply(int n) {
        int sum =0;
        long long x=0 , p=1;

        while(n>0){
            int d = n%10;
            sum+= d;
            if(d!=0){
            x += p* d;
            p*=10;
            }n/=10;
        }
        
        return (x*sum);
        
    }
};