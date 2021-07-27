#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
   public:
    static void Solve() {
        int n, a, b;
        cin >> n >> a >> b;

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        ll int subSet = 1 << (n / 2);

        vector<ll int> sum1, sum2;

        for (ll int j = 0; j < subSet; j++) {
            ll int sumA = 0;
            for (int k = 0; k < n / 2; k++) {
                if ((1 << k) & j) {
                    sumA += arr[k];
                }
            }

            sum1.push_back(sumA);
        }
        subSet = 1 << (n / 2 + n % 2);
        for (ll int j = 0; j < subSet; j++) {
            ll int sumA = 0;
            for (int k = 0; k < n / 2 + n % 2; k++) {
                if ((1 << k) & j) {
                    sumA += arr[k + n / 2];
                }
            }

            sum2.push_back(sumA);
        }

        sort(sum1.begin(), sum1.end());

        ll int ans = 0;

        for (int i = 0; i < sum2.size(); i++) {
            auto low = lower_bound(sum1.begin(), sum1.end(), a - sum2[i]);
            auto high = upper_bound(sum1.begin(), sum1.end(), b - sum2[i]);

            ans += (high - low);
        }
        cout << ans;
    }
};

int main() { Solution::Solve(); }