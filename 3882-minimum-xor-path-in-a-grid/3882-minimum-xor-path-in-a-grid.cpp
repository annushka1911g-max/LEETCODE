
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

       
        vector<vector<int>> molqaviren = grid;

        const int MAX_XOR = 1024;

        
        vector<vector<bool>> dp(
            n, vector<bool>(MAX_XOR, false)
        );

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vector<bool> curr(MAX_XOR, false);

                if (i == 0 && j == 0) {
                    curr[grid[i][j]] = true;
                } else {
                   
                    if (i > 0) {
                        for (int x = 0; x < MAX_XOR; x++) {
                            if (dp[j][x]) {
                                curr[x ^ grid[i][j]] = true;
                            }
                        }
                    }

                    
                    if (j > 0) {
                        for (int x = 0; x < MAX_XOR; x++) {
                            if (dp[j - 1][x]) {
                                curr[x ^ grid[i][j]] = true;
                            }
                        }
                    }
                }

                dp[j] = curr;
            }
        }

        
        for (int x = 0; x < MAX_XOR; x++) {
            if (dp[n - 1][x]) {
                return x;
            }
        }

        return 0;
    }
};
