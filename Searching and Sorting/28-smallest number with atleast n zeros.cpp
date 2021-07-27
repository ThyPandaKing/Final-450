#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int findNum(int n) {
        int left = 0, right = INT_MAX - 1, can = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            int cnt = 0, f = 5;

            while (f <= mid) {
                cnt += mid / f;
                f *= 5;
            }

            // cout<<cnt<<"\n";

            if (cnt < n) {
                left = mid + 1;
            } else {
                can = mid;
                right = mid - 1;
            }
        }
        return can;
    }
};