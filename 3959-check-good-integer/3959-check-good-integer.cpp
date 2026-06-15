class Solution {
public:
    bool checkGoodInteger(int n) {
        int squareSum=0 ,  digitSum = 0 ;
        int temp =n;
            while(temp>0){
            int d = temp%10;
            temp/=10;
            digitSum +=d;
            squareSum += d*d;
        }
        return squareSum-digitSum >= 50;
    }
};