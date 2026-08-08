class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        
//         int n = word1.size();
//         int m = word2.size();

//         // vector<int> suff(m + 1, n);

//         // int p = n - 1;

//         // for(int j = m - 1; j >= 0; --j){

//         //     while(p >= 0 && word1[p] != word2[j]){
//         //         p--;
//         //     }

//         //     if(p < 0)
//         //         break;

//         //     suff[j] = p;
//         //     p--;
//         // }
// vector<array<int, 26>> next(n + 1);

//         next[n].fill(-1);

//         for (int i = n - 1; i >= 0; --i) {
//             next[i] = next[i + 1];
//             next[i][word1[i] - 'a'] = i;
//         }
//         vector<int> ans;
//         int pos = 0;
//         bool used = false;

// // for(int j = 0; j < m; ++j){

// //     while(pos < n){

// //         // Current character matches
// //         if(word1[pos] == word2[j]){

// //             // Remaining word2[j+1...] must be possible
// //             if(suff[j + 1] > pos){
// //                 ans.push_back(pos);
// //                 pos++;
// //                 break;
// //             }
// //         }

// //         // Current character doesn't match.
// //         // Use the one allowed modification.
// //         else if(!used){

// //             // After using modification,
// //             // remaining characters must match exactly.
// //             if(suff[j + 1] > pos){
// //                 ans.push_back(pos);
// //                 pos++;
// //                 used = true;
// //                 break;
// //             }
// //         }

// //         pos++;
// //     }

// //     if(ans.size() != j + 1)
// //         return {};
// // }


//         for (int j = 0; j < m; ++j) {

//             int idx = -1;

//             // 1. Try exact match first.
//             int same = next[pos][word2[j] - 'a'];

//             if (same != -1 && same + (m - j - 1) < n) {
//                 idx = same;
//             }

//             // 2. If mismatch is still available,
//             //    try the earliest DIFFERENT character.
//             if (!used) {

//                 int diff = -1;

//                 for (int c = 0; c < 26; ++c) {

//                     if (c == word2[j] - 'a')
//                         continue;

//                     int x = next[pos][c];

//                     if (x == -1)
//                         continue;

//                     if (x + (m - j - 1) < n) {
//                         diff = x;
//                         break;
//                     }
//                 }

//                 // Choose whichever index is smaller.
//                 if (diff != -1 && (idx == -1 || diff < idx)) {
//                     idx = diff;
//                     used = true;
//                 }
//             }

//             if (idx == -1)
//                 return {};

//             ans.push_back(idx);
//             pos = idx + 1;
//         }

//         return ans;

 int n = word1.size(), m = word2.size();

        vector<int> last(m, -1);

        int i = n - 1, j = m - 1;

        while(i >= 0 && j >= 0) {
            if(word1[i] == word2[j])
                last[j--] = i;
            i--;
        }

        vector<int> ans;
        bool used = false;
        j = 0;

        for(i = 0; i < n && j < m; i++) {

            if(word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            }
            else if(!used && (j == m - 1 || i < last[j + 1])) {
                ans.push_back(i);
                used = true;
                j++;
            }
        }

        if(j != m)
            return {};

        return ans;
    }
};