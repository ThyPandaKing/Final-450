#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
                int max_1_row = 0, i = m - 1, j = 0;

        while (j < n && arr[j][m - 1] == 0) j++;

        if (j == n) return -1;

        while (i >= 0 && arr[j][i] == 1) i--;

        // cout<<i<<" "<<j<<"\n";

        if (i < 0) {
            return j;
        }
        max_1_row = j;

        while (j < n) {
            if (arr[j][i] == 0)
                j++;
            else {
                while (i >= 0 && arr[j][i] == 1) i--;

                if (i < 0) {
                    return j;
                }

                max_1_row = j;

                j++;
            }
        }

        return max_1_row;
    }
};