#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z) {
        vector<int> dp(n + 1, -1);

        dp[0] = 0;
        dp[x] = 1;
        dp[y] = 1;
        dp[z] = 1;

        for (int i = 1; i <= n; i++) {
            if (dp[i] == -1) continue;

            if (i + x <= n) dp[i + x] = max(dp[i + x], dp[i] + 1);
            if (i + y <= n) dp[i + y] = max(dp[i + y], dp[i] + 1);
            if (i + z <= n) dp[i + z] = max(dp[i + z], dp[i] + 1);
        }

        return dp[n] == -1 ? 0 : dp[n];
    }
};