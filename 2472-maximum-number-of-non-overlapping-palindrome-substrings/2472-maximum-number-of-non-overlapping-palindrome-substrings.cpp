class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        // pal[i][j] = true if s[i...j] is a palindrome
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        // Build palindrome table
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                int j = i + len - 1;

                if (len == 1) {
                    pal[i][j] = true;
                }
                else if (len == 2) {
                    pal[i][j] = (s[i] == s[j]);
                }
                else {
                    pal[i][j] = (s[i] == s[j] && pal[i + 1][j - 1]);
                }
            }
        }

        // dp[i] = maximum number of palindromes
        // using first i characters
        vector<int> dp(n + 1, 0);

        for (int j = 1; j <= n; j++) {

            // Don't use a palindrome ending at j-1
            dp[j] = dp[j - 1];

            // Try every starting position
            for (int i = 0; i < j; i++) {

                int len = j - i;

                if (len >= k && pal[i][j - 1]) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }

        return dp[n];
    }
};