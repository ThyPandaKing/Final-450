#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int editDistance(string s, string t) {
        int n = s.size(), m = t.size();

        int dp[n + 1][m + 1];

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = i + j;
                } else {
                    if (s[i - 1] == t[j - 1]) {
                        dp[i][j] = dp[i - 1][j - 1];
                    } else
                        dp[i][j] = min(dp[i - 1][j - 1] + 1,
                                       min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
                }
                // cout<<dp[i][j]<<" ";
            }
            // cout<<"\n";
        }
        return dp[n][m];
    }
};