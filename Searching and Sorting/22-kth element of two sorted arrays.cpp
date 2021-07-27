
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k) {
        if (n > m) {
            return kthElement(arr2, arr1, m, n, k);
        }
        // m > n

        int left = max(0, k - m), right = min(n, k);

        while (left <= right) {
            int first = left + (right - left) / 2;
            int second = k - first;

            int l1 = first > 0 ? arr1[first - 1] : INT_MIN;
            int l2 = second > 0 ? arr2[second - 1] : INT_MIN;
            int r1 = first < n ? arr1[first] : INT_MAX;
            int r2 = second < m ? arr2[second] : INT_MAX;

            // cout<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<"\n";

            if (l1 <= r2 && l2 <= r1) {
                return max(l1, l2);
            } else if (l1 > r2) {
                right = first - 1;
            } else {
                left = first + 1;
            }
        }

        return -1;
    }
};