#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
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
    }

    for (int k : ans) cout << k << " ";

    return 0;
}