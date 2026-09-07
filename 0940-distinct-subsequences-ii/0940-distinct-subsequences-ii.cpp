class Solution {
public:
    int distinctSubseqII(string s) {

        const long long MOD = 1e9 + 7;

        // dp[i] = number of distinct subsequences
        // ending with character ('a' + i)
        vector<long long> dp(26, 0);

        for (char c : s) {

            int idx = c - 'a';

            long long total = 0;

            // Count all current distinct subsequences
            for (int i = 0; i < 26; i++) {
                total = (total + dp[i]) % MOD;
            }

            // New subsequences ending with c
            dp[idx] = (total + 1) % MOD;
        }

        // Sum all subsequences
        long long answer = 0;

        for (int i = 0; i < 26; i++) {
            answer = (answer + dp[i]) % MOD;
        }

        return answer;
    }
};