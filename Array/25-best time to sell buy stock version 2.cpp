#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        int mini = arr[0];
        int maxi = arr[n - 1];
        int profit = 0;

        vector<int> prefix(n);
        vector<int> suffix(n);

        // max profit if sold upto today from left
        for (int i = 1; i < n; i++) {
            prefix[i] = max(prefix[i - 1], arr[i] - mini);
            mini = min(mini, arr[i]);
        }

        // max profit if bought upto today from right
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = max(suffix[i + 1], maxi - arr[i]);
            maxi = max(maxi, arr[i]);
        }

        for (int i = 0; i < n; i++) profit = max(profit, prefix[i] + suffix[i]);

        return profit;
    }
};