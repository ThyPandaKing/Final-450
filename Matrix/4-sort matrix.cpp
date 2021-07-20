#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        // tle will come, but insted of array indx, use priority_queue

        int n = N, m = Mat[0].size(), i = 0, j = 0;

        vector<vector<int>> ans(N, vector<int>(m, 0));

        for (int k = 0; k < n; k++) {
            sort(Mat[k].begin(), Mat[k].end());
        }

        int indx[n] = {0};

        while (i < n) {
            int mn = -1;
            for (int k = 0; k < n; k++) {
                if (indx[k] == -1)
                    continue;
                else if (mn == -1)
                    mn = k;

                if (Mat[k][indx[k]] < Mat[mn][indx[mn]]) {
                    mn = k;
                }
            }

            ans[i][j] = Mat[mn][indx[mn]];
            j++;

            if (j == m) {
                j = 0;
                i++;
            }

            indx[mn]++;
            if (indx[mn] == m) {
                indx[mn] = -1;
            }
        }
        return ans;
    }
};