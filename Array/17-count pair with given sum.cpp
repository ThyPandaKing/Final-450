#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int getPairsCount(int arr[], int n, int k) {
        map<int, int> mp;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            mp[arr[i]]++;
        }

        for (auto m : mp) {
            if (mp[k - m.first]) {
                int a = mp[m.first];
                int b = mp[k - m.first];

                if (m.first == k - m.first) {
                    ans += (a * (b - 1));
                } else {
                    ans += (a * b);
                }
            }
        }
        return ans / 2;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }

    return 0;
}