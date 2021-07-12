#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:

    long long maxProduct(int *arr, int n) {
        // mx = max product till here 
        // mn = max negative till here
        // answer

        long long mx = arr[0], mn = arr[0], ans = arr[0];

        for (int i = 1; i < n; i++) {
            long long temp = mx;

            mx = max((long long)arr[i], max(arr[i] * mx, arr[i] * mn));
            mn = min((long long)arr[i], min(arr[i] * mn, arr[i] * temp));

            ans = max(ans, mx);
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}