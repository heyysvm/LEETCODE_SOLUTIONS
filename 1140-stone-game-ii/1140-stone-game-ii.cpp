class Solution {
public:
    unordered_map<long long, int> memo;

    int solve(vector<int>& piles, int i, int M, vector<int>& suffix) {

        int n = piles.size();

        if (i == n)
            return 0;

        // Encode (i, M) into one key
        long long key = ((long long)i << 32) | M;

        if (memo.count(key))
            return memo[key];

        int ans = 0;
        int rem = suffix[i];

        for (int X = 1; X <= 2 * M && i + X <= n; X++) {

            int newM = max(M, X);

            int opp = solve(piles, i + X, newM, suffix);

            int curr = rem - opp;

            ans = max(ans, curr);
        }

        return memo[key] = ans;
    }

    int stoneGameII(vector<int>& piles) {

        int n = piles.size();

        vector<int> suffix(n + 1, 0);

        for (int i = n - 1; i >= 0; i--)
            suffix[i] = suffix[i + 1] + piles[i];

        return solve(piles, 0, 1, suffix);
    }
};