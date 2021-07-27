#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
   public:
    static void Solve() {
        int n, c;
        cin >> n >> c;

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());

        int left = arr[0], right = arr[n - 1], can = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int lst = 0, cows = 1;

            for (int i = 0; i < n; i++) {
                if (arr[i] - arr[lst] >= mid) {
                    cows++;
                    lst = i;
                }
            }

            if (cows >= c) {
                can = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        cout << can << "\n";
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        Solution::Solve();
    }
}