#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int mod = 1e9 + 7;
    long long int countPS(string s) {
        long long int n = s.size();

        long long int dp[n + 1][n + 1];

        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++) dp[i][j] = 0;

        for (long long int l = 1; l <= n; l++) {
            if (l == 1) {
                // for length one, everything is subsequence
                for (long long int i = 1; i <= n; i++) dp[i][i] = 1ll;
            } else {
                // now we start from i=1, and j=i+l-1 (string i...j)
                // and for i..j =
                // 1. if s[i]==s[j] -> ans[i][j]=ans[i+1][j]+ans[i][j-1]+1;
                // 2. else -> ans[i][j]=ans[i+1][j]+ans[i][j-1]-ans[i+1][j-1];

                // in case sub because of overcount of these values
                for (long long int i = 1; i <= n - l + 1; i++) {
                    long long int j = i + l - 1;
                    if (s[i - 1] == s[j - 1]) {
                        dp[i][j] =
                            (dp[i + 1][j] % mod + dp[i][j - 1] % mod + mod) %
                                mod +
                            1;
                    } else {
                        dp[i][j] = (dp[i + 1][j] % mod + dp[i][j - 1] % mod -
                                    dp[i + 1][j - 1] % mod + mod) %
                                   mod;
                    }
                    dp[i][j] %= mod;
                }
            }
        }

        //   for(int i=1;i<=n;i++,cout<<"\n")for(int j=1;j<=n;j++,cout<<"
        //   ")cout<<dp[i][j];

        return dp[1][n] % mod;
    }
};