#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
   public:
    // Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n) {
        ll sum = 0, cnt = 0;

        unordered_map<ll, ll> mp;

        mp[0] = 1;

        for (int i = 0; i < n; i++) {
            sum += arr[i];

            cnt += mp[sum];

            mp[sum] += 1;
        }

        return cnt;
    }
};