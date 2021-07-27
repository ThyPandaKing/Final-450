#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    long long countTriplets(long long arr[], int n, long long sum) {
        long long cnt = 0;

        sort(arr, arr + n);

        for (int i = 0; i < n; i++) {
            int j = i + 1, k = n - 1;

            while (j < k) {
                int sm = arr[i] + arr[j] + arr[k];

                if (sm >= sum) {
                    k--;
                } else {
                    // cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<"\n";
                    cnt += (k - j);
                    j++;
                }
            }
        }

        return cnt;
    }
};