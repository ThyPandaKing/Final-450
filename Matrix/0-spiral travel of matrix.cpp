#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> spirallyTraverse(vector<vector<int> > a, int n, int m) {
        vector<int> ans;
        // code here
        int left = 0, right = m - 1, up = 0, down = n - 1;

        while (left <= right && up <= down) {
            for (int i = left; i <= right; i++) {
                // cout<<a[up][i]<<" ";
                ans.push_back(a[up][i]);
            }
            up++;

            if (ans.size() >= n * m) break;

            for (int i = up; i <= down; i++) {
                // cout<<a[i][right]<<" ";

                ans.push_back(a[i][right]);
            }
            right--;

            if (ans.size() >= n * m) break;

            for (int i = right; i >= left; i--) {
                // cout<<a[down][i]<<" ";
                ans.push_back(a[down][i]);
            }
            down--;

            if (ans.size() >= n * m) break;

            for (int i = down; i >= up; i--) {
                // cout<<a[i][left]<<" ";
                ans.push_back(a[i][left]);
            }
            left++;

            /**
             * @brief instead of checking for size in every step, try this
             *  if (k < m) {
             *     for (i = n - 1; i >= l; --i) {
             *       cout << a[m - 1][i] << " ";
             *     }
             *     m--;
             *   }
             *   if (l < n) {
             *     for (i = m - 1; i >= k; --i) {
             *        cout << a[i][l] << " ";
             *     }
             *     l++;
             *   }
             *
             */
        }
        return ans;
    }
};