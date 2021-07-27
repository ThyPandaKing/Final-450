#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int>& nums) {
        vector<pair<int, int>> a;

        for (int i = 0; i < nums.size(); i++) {
            a.push_back({nums[i], i});
        }

        bool vis[nums.size()] = {0};

        sort(a.begin(), a.end());
        int cnt = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (vis[i] == 0) {
                int idx = i, c = 0;

                while (vis[idx] == 0) {
                    c++;
                    vis[idx] = true;
                    idx = a[idx].second;
                }

                cnt += (c - 1);
            }
        }
        return cnt;
    }
};