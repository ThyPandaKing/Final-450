#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

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
                dp[j] %= mod;
            }
        }
        return dp[r] % mod;
    }
};