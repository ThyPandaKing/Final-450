#include <bits/stdc++.h>
using namespace std;


class Solution {
   public:
    int maxGold(int n, int m, vector<vector<int>> M) {
        int dp[n][m];

        int ans = 0;

        for (int i = 0; i < n; i++) {
            dp[i][0] = M[i][0];

            ans = max(ans, dp[i][0]);
        }

        for (int j = 1; j < m; j++) {
            for (int i = 0; i < n; i++) {
                int x = i > 0 ? dp[i - 1][j - 1] : 0;
                int y = dp[i][j - 1];
                int z = i < n - 1 ? dp[i + 1][j - 1] : 0;

                dp[i][j] = max(x, max(y, z)) + M[i][j];
                // cout<<dp[i][j]<<" ";
                ans = max(ans, dp[i][j]);
            }
            // cout<<"\n";
        }

        return ans;
    }
};