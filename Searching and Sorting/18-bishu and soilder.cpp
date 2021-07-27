#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
   public:
    static void BishuPower(vector<ll int>& nums) {
        sort(nums.begin(), nums.end());
        vector<ll int> prefix(nums.size());
        prefix[0] = nums[0];

        for (int i = 1; i < nums.size(); i++)
            prefix[i] = prefix[i - 1] + nums[i];

        int q;
        cin >> q;

        while (q--) {
            int power;
            cin >> power;
            int left = 0, right = nums.size() - 1, last = -1;

            while (left <= right) {
                int mid = left + (right - left) / 2;

                if (nums[mid] <= power) {
                    left = mid + 1;
                    last = mid;
                } else {
                    right = mid - 1;
                }
            }
            if (last == -1) {
                cout << 0 << " " << 0 << "\n";
                continue;
            }
            cout << last + 1 << " " << prefix[last] << "\n";
        }
    }
};

int main() {
    ll int n;
    cin >> n;

    vector<ll int> nums(n);

    for (int i = 0; i < n; i++) cin >> nums[i];

    Solution::BishuPower(nums);
}