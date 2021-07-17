#include <bits/stdc++.h>
using namespace std;

vector<string> input = {"DDDGDD", "BBDEBS", "BSKEBK",
                        "DDDDDE", "DDDDDE", "DDDDDG"};

int cnt_recurr(int i, int j, int indx, string a) {
    int cnt = 0;

    if (i < 0 || i >= input.size() || j < 0 || j >= input[0].size()) return 0;

    if (indx == a.size() - 1) {
        return a[indx] == input[i][j];
    }

    if (input[i][j] == a[indx]) {
        cnt = cnt_recurr(i + 1, j, indx + 1, a) +
              cnt_recurr(i, j + 1, indx + 1, a) +
              cnt_recurr(i - 1, j, indx + 1, a) +
              cnt_recurr(i, j - 1, indx + 1, a);
    }

    return cnt;
}

void find_count(string a) {
    int n = input.size(), m = input[0].size();
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (input[i][j] == a[0]) {
                cnt +=
                    (cnt_recurr(i + 1, j, 1, a) + cnt_recurr(i, j + 1, 1, a) +
                     cnt_recurr(i - 1, j, 1, a) + cnt_recurr(i, j - 1, 1, a));
            }
        }
    }
    cout << cnt << endl;
}

// Driver code
int main() {
    string a;
    cin >> a;
    find_count(a);

    return 0;
}
