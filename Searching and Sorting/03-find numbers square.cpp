#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int countSquares(int N) {
        long long int left = 1, right = N;
        int ans = 0;

        while (left <= right) {
            long long int mid = left + (right - left) / 2;

            if (mid * mid < N) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};