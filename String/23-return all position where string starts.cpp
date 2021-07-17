#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool cnt_recurr(int i, int j, pair<int, int> pr, string a,
                    vector<vector<char>> grid) {
        for (int k = 1; k < a.size(); k++) {
            if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
                return false;

            if (a[k] != grid[i][j]) return false;

            i += pr.first;
            j += pr.second;
        }

        return true;
    }

    vector<vector<int>> searchWord(vector<vector<char>> grid, string a) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> sol;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == a[0]) {
                    if (cnt_recurr(i + 1, j, {1, 0}, a, grid) ||
                        cnt_recurr(i, j + 1, {0, 1}, a, grid) ||
                        cnt_recurr(i - 1, j, {-1, 0}, a, grid) ||
                        cnt_recurr(i, j - 1, {0, -1}, a, grid) ||
                        cnt_recurr(i + 1, j + 1, {1, 1}, a, grid) ||
                        cnt_recurr(i - 1, j + 1, {-1, 1}, a, grid) ||
                        cnt_recurr(i - 1, j - 1, {-1, -1}, a, grid) ||
                        cnt_recurr(i + 1, j - 1, {1, -1}, a, grid))

                    {
                        sol.push_back({i, j});
                    }
                }
            }
        }
        return sol;
    }
};