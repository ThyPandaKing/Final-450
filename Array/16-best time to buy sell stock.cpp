#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxProfit(vector<int>& a) {
        int n = a.size(), i, mx = 0;
        if (n == 0) return 0;
        int nan = a[n - 1];

        for (i = n - 2; i >= 0; i--) {
            nan = max(a[i], nan);

            mx = max(mx, nan - a[i]);
        }
        return mx;
    }
};