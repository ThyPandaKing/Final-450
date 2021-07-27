#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
   public:
    static ll int find_max_profit(
        vector<pair<pair<ll int, ll int>, ll int>>& nums) {
        sort(nums.begin(), nums.end(),
             [=](pair<pair<ll int, ll int>, ll int> a,
                 pair<pair<ll int, ll int>, ll int> b) {
                 return a.first.second < b.first.second;
             });

        vector<int> profit(nums.size(), 0);

        // profit[i] contains max profit till i

        profit[0] = nums[0].second;

        for (int i = 1; i < nums.size(); i++) {
            int maxInc = nums[i].second;

            int left = 0, right = i - 1, md=-1;

            while (left <= right) {
                int mid = left + (right - left) / 2;

                if (nums[mid].first.second <= nums[i].first.first) {
                    if (nums[mid + 1].first.second <= nums[i].first.first) {
                        left = mid + 1;
                    } else {
                        md = mid;
                        break;
                    }
                } else {
                    right = mid - 1;
                }
            }

            if(md != -1)maxInc += profit[md];


            profit[i] = max(maxInc, profit[i - 1]);
        }

        return profit[nums.size()-1];
    }
};

int main() {
    int n;
    cin >> n;
    vector<pair<pair<ll int, ll int>, ll int>> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i].first.first >> nums[i].first.second >> nums[i].second;

    cout << Solution::find_max_profit(nums);
}