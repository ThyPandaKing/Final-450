#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int up = 0, down = n - 1;
        int req_row = -1;

        while (up <= down) {
            int mid = up + (down - up) / 2;

            if (matrix[mid][0] <= target && matrix[mid][m - 1] >= target) {
                req_row = mid;
                break;
            } else {
                if (matrix[mid][0] > target) {
                    down = mid - 1;
                } else {
                    up = mid + 1;
                }
            }
        }

        if (req_row == -1) return false;

        int left = 0, right = m - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (matrix[req_row][mid] == target) {
                return true;
            } else {
                if (matrix[req_row][mid] > target) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }

        return false;
    }
};