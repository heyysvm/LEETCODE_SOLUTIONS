// class Solution {
// public:
//     string smallestNumber(string num, long long t) {
        
//         // string ans="-1";
//         // long long  n = stoll(num);
        
//         // while(true){
//         //     long long temp = n;
//         //     long long prod = 1; 
//         //     bool zeroFree = true;
//         //   while(temp>0){
//         //     int d= temp%10;
//         //     if(d==0){
//         //         zeroFree = false;
//         //         break;
//         //     }
//         //     prod*=d;
//         //     temp/=10;
//         // }
//         // if(zeroFree && prod%t == 0 ) return to_string(n);
//         // n++;
//         // }
//         // return "-1";

// //     vector<int> needVec(4);

// //     needVec[0] = need[2];
// //     needVec[1] = need[3];
// //     needVec[2] = need[5];
// //     needVec[3] = need[7];

// //  vector<int> have(4,0);

// //         for(char c:num){
// //             int d = c-'0';

// //             for(int i =0;i<4;i++){
// //                 have[i] += cnt[d][i];
// //             }
// //         }

// // bool okass = true;
    
// //     for(int i=0;i<4;i++){
// //         if(have[i] < needVec[i]){
// //             okass = false;
// //             break;
// //         }
// //     }

// //     if(okass) return num;

// //     int len = num.size();

// // for(int i =len-1;i>=0;i--){
// //     int d = num[i]-'0';

// //     for(int j=0;j<4;j++){
// //         have[j]=cnt[d][j];
// //     }
// // }

// //         map<int,int> need;

// //         for(int p :{2,3,5,7}) {
// //             while(t%p ==0){
// //                 need[p]++;
// //                 t /=p;
// //             }
// //         }
// //         if(t != 1) return "-1";

// //         vector<vector<int>> cnt ={
// //             {0,0,0,0},
// //             {0,0,0,0},
// //             {1,0,0,0},
// //             {0,1,0,0},
// //             {2,0,0,0},
// //             {0,0,1,0},
// //             {1,1,0,0},
// //             {0,0,0,1},
// //             {3,0,0,0},
// //             // {0,0,0,2}
// //             {0,2,0,0};
// //         }

       
// #include <iostream>
// #include <string>
// #include <vector>
// #include <algorithm>

// using namespace std;

// class Solution {
//     struct Factors {
//         long long count2 = 0;
//         long long count3 = 0;
//         long long count5 = 0;
//         long long count7 = 0;
//     };

//     Factors reduce(Factors f, int digit) {
//         if (digit == 2) f.count2 = max(0LL, f.count2 - 1);
//         if (digit == 3) f.count3 = max(0LL, f.count3 - 1);
//         if (digit == 4) f.count2 = max(0LL, f.count2 - 2);
//         if (digit == 5) f.count5 = max(0LL, f.count5 - 1);
//         if (digit == 6) {
//             f.count2 = max(0LL, f.count2 - 1);
//             f.count3 = max(0LL, f.count3 - 1);
//         }
//         if (digit == 7) f.count7 = max(0LL, f.count7 - 1);
//         if (digit == 8) f.count2 = max(0LL, f.count2 - 3);
//         if (digit == 9) f.count3 = max(0LL, f.count3 - 2);
//         return f;
//     }

//     int getMinDigitsNeeded(Factors f) {
//         long long c2 = max(0LL, f.count2);
//         long long c3 = max(0LL, f.count3);
//         long long c5 = max(0LL, f.count5);
//         long long c7 = max(0LL, f.count7);

//         int total = c5 + c7;

//         total += (c2 / 3);
//         total += (c3 / 2);

//         int rem2 = c2 % 3;
//         int rem3 = c3 % 2;

//         if (rem2 == 0 && rem3 == 0) {
            
//         } else if (rem2 == 2 && rem3 == 1) {
//             total += 2;
//         } else {
//             total += 1;
//         }

//         return total;
//     }
//         Factors required;

//         while (t % 2 == 0) { required.count2++; t /= 2; }
//         while (t % 3 == 0) { required.count3++; t /= 3; }
//         while (t % 5 == 0) { required.count5++; t /= 5; }
//         while (t % 7 == 0) { required.count7++; t /= 7; }

//         if (t != 1) return "-1";

//         int n = num.size();

//         int zeroPos = n;
//         for (int i = 0; i < n; i++) {
//             if (num[i] == '0') {
//                 zeroPos = i;
//                 break;
//             }
//         }

//         vector<Factors> prefixFactors(n + 1);
//         prefixFactors[0] = required;
//         for (int i = 0; i < zeroPos; i++) {
//             prefixFactors[i + 1] = reduce(prefixFactors[i], num[i] - '0');
//         }

//         for (int i = n; i >= 0; i--) {
//             if (i > zeroPos) continue;

//             if (i == n) {
//                 Factors current = prefixFactors[n];
//                 if (current.count2 == 0 && current.count3 == 0 && current.count5 == 0 && current.count7 == 0) {
//                     return num;
//                 }
//                 continue;
//             }

//             int startDigit = (i == zeroPos) ? 1 : (num[i] - '0' + 1);

//             for (int d = startDigit; d <= 9; d++) {
//                 Factors nextFactors = reduce(prefixFactors[i], d);
//                 int remainingLength = n - 1 - i;

//                 if (getMinDigitsNeeded(nextFactors) <= remainingLength) {
//                     string result = num.substr(0, i);
//                     result += to_string(d);

//                     Factors current = nextFactors;
//                     for (int j = 0; j < remainingLength; j++) {
//                         for (int fill = 1; fill <= 9; fill++) {
//                             Factors temp = reduce(current, fill);
//                             if (getMinDigitsNeeded(temp) <= remainingLength - 1 - j) {
//                                 result += to_string(fill);
//                                 current = temp;
//                                 break;
//                             }
//                         }
//                     }
//                     return result;
//                 }
//             }
//         }

//         int minLen = getMinDigitsNeeded(required);
//         int targetLen = max(n + 1, minLen);

//         string result = "";
//         Factors current = required;

//         for (int j = 0; j < targetLen; j++) {
//             for (int fill = 1; fill <= 9; fill++) {
//                 Factors temp = reduce(current, fill);
//                 if (getMinDigitsNeeded(temp) <= targetLen - 1 - j) {
//                     result += to_string(fill);
//                     current = temp;
                    
//                 }
//             }
//         }

//         return result;
//     }
// };


class Solution {
    struct Factors {
        long long count2 = 0;
        long long count3 = 0;
        long long count5 = 0;
        long long count7 = 0;
    };

    Factors reduce(Factors f, int digit) {
        if (digit == 2) f.count2 = max(0LL, f.count2 - 1);
        if (digit == 3) f.count3 = max(0LL, f.count3 - 1);
        if (digit == 4) f.count2 = max(0LL, f.count2 - 2);
        if (digit == 5) f.count5 = max(0LL, f.count5 - 1);
        if (digit == 6) {
            f.count2 = max(0LL, f.count2 - 1);
            f.count3 = max(0LL, f.count3 - 1);
        }
        if (digit == 7) f.count7 = max(0LL, f.count7 - 1);
        if (digit == 8) f.count2 = max(0LL, f.count2 - 3);
        if (digit == 9) f.count3 = max(0LL, f.count3 - 2);
        return f;
    }

    int getMinDigitsNeeded(Factors f) {
        long long c2 = max(0LL, f.count2);
        long long c3 = max(0LL, f.count3);
        long long c5 = max(0LL, f.count5);
        long long c7 = max(0LL, f.count7);

        int total = c5 + c7;

        total += (c2 / 3);
        total += (c3 / 2);

        int rem2 = c2 % 3;
        int rem3 = c3 % 2;

        if (rem2 == 0 && rem3 == 0) {
            
        } else if (rem2 == 2 && rem3 == 1) {
            total += 2;
        } else {
            total += 1;
        }

        return total;
    }

public:
    string smallestNumber(string num, long long t) {
        Factors required;

        while (t % 2 == 0) { required.count2++; t /= 2; }
        while (t % 3 == 0) { required.count3++; t /= 3; }
        while (t % 5 == 0) { required.count5++; t /= 5; }
        while (t % 7 == 0) { required.count7++; t /= 7; }

        if (t != 1) return "-1";

        int n = num.size();

        int zeroPos = n;
        for (int i = 0; i < n; i++) {
            if (num[i] == '0') {
                zeroPos = i;
                break;
            }
        }

        vector<Factors> prefixFactors(n + 1);
        prefixFactors[0] = required;
        for (int i = 0; i < zeroPos; i++) {
            prefixFactors[i + 1] = reduce(prefixFactors[i], num[i] - '0');
        }

        for (int i = n; i >= 0; i--) {
            if (i > zeroPos) continue;

            if (i == n) {
                Factors current = prefixFactors[n];
                if (current.count2 == 0 && current.count3 == 0 && current.count5 == 0 && current.count7 == 0) {
                    return num;
                }
                continue;
            }

            int startDigit = (i == zeroPos) ? 1 : (num[i] - '0' + 1);

            for (int d = startDigit; d <= 9; d++) {
                Factors nextFactors = reduce(prefixFactors[i], d);
                int remainingLength = n - 1 - i;

                if (getMinDigitsNeeded(nextFactors) <= remainingLength) {
                    string result = num.substr(0, i);
                    result += to_string(d);

                    Factors current = nextFactors;
                    for (int j = 0; j < remainingLength; j++) {
                        for (int fill = 1; fill <= 9; fill++) {
                            Factors temp = reduce(current, fill);
                            if (getMinDigitsNeeded(temp) <= remainingLength - 1 - j) {
                                result += to_string(fill);
                                current = temp;
                                break;
                            }
                        }
                    }
                    return result;
                }
            }
        }

        int minLen = getMinDigitsNeeded(required);
        int targetLen = max(n + 1, minLen);

        string result = "";
        Factors current = required;

        for (int j = 0; j < targetLen; j++) {
            for (int fill = 1; fill <= 9; fill++) {
                Factors temp = reduce(current, fill);
                if (getMinDigitsNeeded(temp) <= targetLen - 1 - j) {
                    result += to_string(fill);
                    current = temp;
                    break;
                }
            }
        }

        return result;
    }
};