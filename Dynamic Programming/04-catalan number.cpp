#include <bits/stdc++.h>
using namespace std;


class Solution {
   public:
    int nCr(int n, int r) {
        if (r > n) return 0;

        if (r == n) return 1;

        if (r == 1) return n;

        int dp[r + 1] = {0};

        // nCr = (n-1)C(r-1) + (n-1)Cr
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = min(r, i); j > 0; j--) {
                dp[j] = dp[j - 1] + dp[j];
            }
        }
        return dp[r];
    }
    // Function to find the nth catalan number.
    int findCatalan(int n) {
        // nth catalan number ->
        // 2nCn / (n+1)

        /**
         *
         * nCr = n-1Cr-1 + n-1Cr
         *
         */

        return nCr(2 * n, n) / (n + 1);
    }
};