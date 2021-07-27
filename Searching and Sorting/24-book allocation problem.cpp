#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
   public:
    int findPages(int arr[], int n, int m)

    {
        ll int left = 0, right = 0, can = -1;

        for (int i = 0; i < n; i++) right += arr[i];

        while (left <= right) {
            ll int mid = left + (right - left) / 2;

            // we check if it's possible to get this as max

            ll int sm = 0;
            int ttl = 1;

            for (int i = 0; i < n; i++) {
                if (arr[i] > mid) {
                    ttl = 1e18;
                    break;
                }

                if (sm + arr[i] > mid) {
                    ttl++;
                    sm = arr[i];
                } else {
                    sm += arr[i];
                }
            }

            if (ttl <= m) {
                can = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }

            // cout<<left << " " << can <<" " <<right<<"\n";
        }

        return can;
    }
};