#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
   public:
    static vector<pair<ll int, ll int>> mergeInterval(
        vector<pair<ll int, ll int>> &arr) {
        if (arr.size() == 1) {
            return arr;
        }
        vector<pair<ll int, ll int>> ans;
        sort(arr.begin(), arr.end());
        ll int first = arr[0].first;
        ll int second = arr[0].second;

        for (ll int i = 1; i < arr.size(); i++) {
            while (i < arr.size() && second >= arr[i].first) {
                second = max(arr[i].second, second);
                i++;
            }
            ans.push_back({first, second});

            if (i < arr.size()) {
                first = arr[i].first;
                second = arr[i].second;
            }
        }
        ans.push_back({first, second});

        return ans;
    }
    static void KSmall() {
        ll int n, q;
        cin >> n >> q;

        vector<pair<ll int, ll int>> arr(n);
        vector<pair<ll int, ll int>> merged;
        for (ll int i = 0; i < n; i++) {
            cin >> arr[i].first >> arr[i].second;
        }
        merged = mergeInterval(arr);

        vector<ll int> pre(merged.size());

        pre[0] = merged[0].second - merged[0].first + 1;

        // cout << pre[0] << " ";

        for (ll int i = 1; i < merged.size(); i++) {
            pre[i] = merged[i].second - merged[i].first + 1 + pre[i - 1];

            // cout << pre[i] << " ";
        }

        // cout << "\n";
        while (q--) {
            ll int left = 0, right = merged.size() - 1, ceil;
            ll int k;
            cin >> k;

            if (k > pre[right]) {
                cout << "-1\n";
                continue;
            }

            while (left <= right) {
                ll int mid = left + (right - left) / 2;
                if (pre[mid] < k) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                    ceil = mid;
                }
            }

            cout << merged[ceil].first + (k - (ceil == 0 ? 0 : pre[ceil - 1])) -
                        1
                 << "\n";
        }
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) Solution::KSmall();
}