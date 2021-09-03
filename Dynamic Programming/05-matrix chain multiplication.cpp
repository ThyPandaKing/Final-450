#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int matrixMultiplication(int n, int arr[]) {
        int dp[n][n];

        for (int i = 0; i < n; i++) {
            dp[i][i] = 0;
        }

        for (int len = 2; len <= n; len++) {
            for (int i = 1; i < n - len + 1; i++) {
                int j = i + len - 1;

                dp[i][j] = INT_MAX;

                for (int k = i; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] +
                                                 arr[i - 1] * arr[k] * arr[j]);
                }
            }
        }

        return dp[1][n - 1];
    }
};