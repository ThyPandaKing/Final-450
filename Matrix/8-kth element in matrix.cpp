#include <bits/stdc++.h>

using namespace std;
#define MAX 100

int kthSmallest(int mat[MAX][MAX], int n, int k) {
    int start = mat[0][0], end = mat[n - 1][n - 1];

    k--;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        int cnt_less = 0;

        for (int i = 0; i < n; i++) {
            int left = 0, right = n - 1, indx = 0;

            while (left <= right) {
                int md = left + (right - left) / 2;

                if (mat[i][md] > mid) {
                    right = md - 1;
                } else {
                    indx = md + 1;
                    left = md + 1;
                }
            }

            cnt_less += indx;
        }

        if (cnt_less <= k) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return start;
}