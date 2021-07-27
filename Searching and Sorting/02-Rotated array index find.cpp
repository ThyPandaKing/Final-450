#include <bits/stdc++.h>

using namespace std;

// <-- METHOD 1 -->

class Solution1 {
   public:
    int search(vector<int>& nums, int target) {
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
        // answer is between 0----rotated-1 or rotated-----n-1

        if (nums[n - 1] >= target) {
            left = rotated, right = n - 1;
        } else {
            left = 0, right = rotated - 1;
        }

        // cout<<rotated<<" "<<left<<" "<<right<<"\n";

        while (right >= left) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;

            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        // cout<<rotated<<" "<<left<<" "<<right<<"\n";

        return -1;
    }
};

// <-- METHOD 2 -->

class Solution2 {
   public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        int n = nums.size();

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] >= nums[left]) {
                // sorted from left-mid
                if (nums[mid] > target && nums[left] <= target) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                // sorted from mid-right
                if (nums[mid] < target && nums[right] >= target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }

            // cout<<mid<<" "<<left<<" "<<right<<"\n";
        }

        return -1;
    }
};