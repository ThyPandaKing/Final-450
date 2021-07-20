#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    void rotate(vector<vector<int>>& matrix) {
        // take transpose

        int n = matrix.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // swap every row till mid
        int half = n / 2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < half; j++) {
                swap(matrix[i][j], matrix[i][n - j - 1]);
            }
        }
        // return matrix;
    }
};