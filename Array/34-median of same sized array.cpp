#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    static double findMedianSortedArrays(vector<int>& nums1,
                                         vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();

        if (m < n) {
            return findMedianSortedArrays(nums2, nums1);
        }

        if (n == 0) {
            return m % 2 ? nums2[m / 2]
                         : (double)(nums2[m / 2] + nums2[m / 2 - 1]) / 2.0;
        } else if (m == 0) {
            return n % 2 ? nums1[n / 2]
                         : (double)(nums1[n / 2] + nums1[n / 2 - 1]) / 2.0;
        }

        int l = 0, r = n;

        while (l <= r) {
            int parX = l + (r - l) / 2;
            int parY = (n + m + 1) / 2 - parX;

            int maxLeftX = (parX == 0) ? INT_MIN : nums1[parX - 1];
            int minRightX = (parX == n) ? INT_MAX : nums1[parX];

            int maxLeftY = (parY == 0) ? INT_MIN : nums2[parY - 1];
            int minRightY = (parY == m) ? INT_MAX : nums2[parY];

            // cout << maxLeftX << " " << maxLeftY << " " << minRightX << " "
            //  << minRightY << "\n";

            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                double result;

                if ((n + m) % 2 == 0) {
                    result = (double)(max(maxLeftX, maxLeftY) +
                                      min(minRightX, minRightY)) /
                             2.0;

                    // cout<<max(maxLeftX, maxLeftX) << " " << min(minRightX,
                    // minRightY);
                } else {
                    result = max(maxLeftX, maxLeftY);
                }

                return result;
            } else if (maxLeftX > minRightY) {
                // go left in a
                r = parX - 1;
            } else {
                l = parX + 1;
            }
        }
        // return findMedianSortedArrays(nums2,nums1);
        return -1;
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n;
        cin >> m;

        vector<int> a(n), b(m);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }

        cout << Solution::findMedianSortedArrays(a, b) << endl;
    }

    return 0;
}