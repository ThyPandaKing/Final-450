#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int LongestRepeatingSubsequence(string str) {
        int n = str.length();
        // like LCS, only difference is we can't use same i,j
        int dp[n + 1][n + 1];

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                dp[i][j] = 0;
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                // same character with index not same
                if (str[i - 1] == str[j - 1] && i != j) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    // otherwise
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][n];
    }
};