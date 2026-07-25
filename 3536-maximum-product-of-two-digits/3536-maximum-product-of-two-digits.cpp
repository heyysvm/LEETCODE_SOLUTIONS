class Solution {
public:
    int maxProduct(int n) {
        int largest = 0, secondl =0;
        while(n){
            int digit = n%10;
            n/=10;
            if(digit>secondl){
                secondl=digit;
                if(digit>largest){
                    secondl=largest;
                    largest=digit;
                }
            }

        }
        return largest*secondl;
    }
};