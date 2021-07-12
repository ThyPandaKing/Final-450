#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) return;

        int i = nums.size() - 1;

        while (nums[i - 1] >= nums[i]) {
            i--;
            if (i == 0) {
                sort(nums.begin(), nums.end());
                return;
            }
        }

        int indx = i, j = nums.size() - 1;

        while (nums[j] <= nums[i - 1]) j--;

        swap(nums[i - 1], nums[j]);

        sort(nums.begin() + i, nums.end());
    }
};
