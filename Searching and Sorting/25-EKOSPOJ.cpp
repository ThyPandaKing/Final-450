#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
   public:
    static ll int minCut(vector<ll int>& nums, ll int k) {
        sort(nums.begin(), nums.end());
        ll int left = 0, right = nums.back();
        ll int ans = -1;
        while (left <= right) {
            ll int mid = left + (right - left) / 2;
            ll int wood = 0;
            for (ll int ele : nums) {
                wood += (ele < mid ? 0 : ele - mid);
            }

            if (wood >= k) {
                left = mid + 1;
                ans = mid;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    ll int n, k;
    cin >> n >> k;

    vector<ll int> nums(n);

    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << Solution::minCut(nums, k);
}