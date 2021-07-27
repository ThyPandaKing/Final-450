#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int getMinDiff(int a[], int n, int k) {
        sort(a, a + n);

        int res = a[n - 1] - a[0];

        for (int i = 0; i < n - 1; i++) {
            if (a[i + 1] >= k && a[n - 1] >= k) {
                int mx = max(a[i] + k, a[n - 1] - k);

                int mn = min(a[0] + k, a[i + 1] - k);

                res = min(res, mx - mn);
            }
        }

        return res;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}