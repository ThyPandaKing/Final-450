#include <bits/stdc++.h>

using namespace std;
#define MAX 5

void CommonElement(int mat[MAX][MAX], int n) {
    unordered_map<int, int> mp;

    for (int j = 0; j < n; j++) mp[mat[0][j]] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mp[mat[i][j]] == i) {
                mp[mat[i][j]] = i + 1;
                if (i == n - 1) {
                    cout << mat[i][j] << "\n";
                }
            }
        }
    }
}

int main() {
    int mat[5][5] = {{1, 2, 1, 7, 8},
                     {3, 7, 8, 5, 1},
                     {8, 7, 7, 3, 1},
                     {8, 1, 2, 7, 9},
                     {1, 8, 7, 0, 9}};

    CommonElement(mat, 5);

    return 0;
}