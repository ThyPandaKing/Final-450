#include <bits/stdc++.h>

using namespace std;
#define MAX 5

void maximum_diff_pair(int mat[MAX][MAX], int n) {
    int max_arr[MAX][MAX];

    max_arr[n - 1][n - 1] = mat[n - 1][n - 1];

    for (int j = n - 2; j >= 0; j--) {
        max_arr[n - 1][j] = max(max_arr[n - 1][j + 1], mat[n - 1][j]);
    }
    for (int j = n - 2; j >= 0; j--) {
        max_arr[j][n - 1] = max(max_arr[j + 1][n - 1], mat[j][n - 1]);
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int j = n - 2; j >= 0; j--) {
            max_arr[i][j] =
                max(max(max_arr[i + 1][j], max_arr[i][j + 1]), mat[i][j]);
        }
    }

    int ans = 0;

    for (int i = n - 2; i >= 0; i--) {
        for (int j = n - 2; j >= 0; j--) {
            ans = max(max_arr[i + 1][j + 1] - mat[i][j], ans);
        }
    }

    // for (int i = 0; i < n; i ++,cout<<"\n") {
    //     for (int j = 0; j<n; j++) {
    //         cout<<max_arr[i][j]<<" ";
    //     }
    // }

    cout << ans;
}

int main() {
    int mat[5][5] = {{1, 2, -1, -4, -20},
                     {-8, -3, 4, 2, 1},
                     {3, 8, 6, 1, 3},
                     {-4, -1, 1, 7, -6},
                     {0, -4, 10, -5, 1}};

    maximum_diff_pair(mat, 5);

    return 0;
}