#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;

class Solution {
   public:
    // Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2) {
        int n = s1.size(), m = s2.size();
        int dp[n + 1][m + 1];

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                dp[i][j] = 0;
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n][m];
    }
};
