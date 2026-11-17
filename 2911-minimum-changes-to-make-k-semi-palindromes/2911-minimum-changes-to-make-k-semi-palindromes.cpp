
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;

        vector<vector<int>> cost(n, vector<int>(n, INF));

        
        for (int len = 2; len <= n; len++) {
            for (int l = 0; l + len <= n; l++) {
                int r = l + len - 1;

                
                for (int d = 1; d < len; d++) {
                    if (len % d != 0) continue;

                    int changes = 0;

                    
                    for (int rem = 0; rem < d; rem++) {
                        int left = l + rem;
                        int right = r - ((len - 1 - rem) % d);

                        while (left < right) {
                            if (s[left] != s[right]) {
                                changes++;
                            }

                            left += d;
                            right -= d;
                        }
                    }

                    cost[l][r] = min(cost[l][r], changes);
                }
            }
        }

        vector<vector<int>> dp(n + 1,
                               vector<int>(k + 1, INF));

        dp[0][0] = 0;

        for (int groups = 1; groups <= k; groups++) {
            for (int i = 1; i <= n; i++) {

                
                for (int pos = 0; pos < i; pos++) {
                    int len = i - pos;

                    
                    if (len < 2) continue;

                    if (dp[pos][groups - 1] == INF) {
                        continue;
                    }

                    dp[i][groups] = min(
                        dp[i][groups],
                        dp[pos][groups - 1] + cost[pos][i - 1]
                    );
                }
            }
        }

        return dp[n][k];
    }
};
