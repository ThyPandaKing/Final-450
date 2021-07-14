#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int trappingWater(int arr[], int n) {
        int mxArrL[n], mx = arr[0], mxArrR[n], mn = arr[n - 1];

        int ans = 0;

        mxArrL[0] = 0;

        mxArrR[n - 1] = 0;

        for (int i = 1; i < n; i++) {
            mxArrL[i] = mx;
            mx = max(mx, arr[i]);
        }
        for (int i = n - 2; i >= 0; i--) {
            mxArrR[i] = mn;
            mn = max(mn, arr[i]);
        }

        for (int i = 1; i < n - 1; i++) {
            ans += max(0, min(mxArrL[i], mxArrR[i]) - arr[i]);
        }

        return ans;
    }
};

int main() {
    int t;
    // testcases
    cin >> t;

    while (t--) {
        int n;

        // size of array
        cin >> n;

        int a[n];

        // adding elements to the array
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution obj;
        // calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
    }

    return 0;
}