#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
   public:
    static void solve() {
        int sum, n;
        cin >> sum >> n;

        vector<int> a(n), cnt(9, 0);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }

        ll int left = 0, right = 1e9, can = -1;

        while (left <= right) {
            ll int mid = left + (right - left) / 2ll;

            ll int paratha = 0;

            // to check how many paratha we can make in "mid" time
            for (int i = 1; i <= 8; i++) {
                int l = 0, r = 1001, nn = 0;

                while (l <= r) {
                    int md = l + (r - l) / 2;
                    int val = i * (md * (md + 1)) / 2;

                    if (val <= mid) {
                        l = md + 1;

                        nn = md;
                    } else {
                        r = md - 1;
                    }
                }
                // cout << cnt[i] << " " << nn << " " << paratha << "\n";
                paratha += cnt[i] * nn;
            }
            // cout << paratha << " " << sum << " " << left << " " << right << "
            // "
            //      << mid << "\n";
            if (paratha >= sum) {
                can = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        cout << can << "\n";
    }
};

int main() {
    int t;

    cin >> t;

    while (t--) {
        Solution::solve();
    }
}