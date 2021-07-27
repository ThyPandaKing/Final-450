#include <bits/stdc++.h>

using namespace std;

// <-- METHOD 1 -->

class Solution1 {
   public:
    int searchPivot(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int rotated = -1;
        int n = nums.size();

        while (right >= left) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[(mid + 1) % n]) {
                rotated = (mid + 1) % n;
                break;
            } else if (nums[mid] > nums[n - 1]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        rotated = rotated == -1 ? 0 : rotated;

        return -1;
    }
};
