#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[]) {
        vector<int> dp;

        for (int i = 0; i < n; i++) {
            if (dp.size() == 0 || a[i] > dp.back()) {
                dp.push_back(a[i]);
            } else {
                int it = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();

                dp[it] = a[i];
            }
        }
        return dp.size();
    }
};