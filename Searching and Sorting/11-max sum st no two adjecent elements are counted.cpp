#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution {
   public:
    int FindMaxSum(int arr[], int n) {
        int sum[n] = {0};

        sum[0] = arr[0];
        sum[1] = max(arr[0], arr[1]);

        for (int i = 2; i < n; i++) {
            sum[i] = max(arr[i] + sum[i - 2], sum[i - 1]);
        }

        return sum[n - 1];
    }
};