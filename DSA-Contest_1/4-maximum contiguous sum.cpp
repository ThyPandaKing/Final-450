#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++) cin >> a[i];

    int left = 0, right = -1, start = 0;
    bool f = false;

    int ans = 0, max_sum = INT_MIN;

    for (int i = 0; i < n; i++) {
        ans += a[i];

        if (ans < 0) {
            ans = 0;
            left = i + 1;
        } else {
            f = true;

            if (ans > max_sum) {
                right = i;
                start = left;
                max_sum = ans;
            }
        }
    }

    if (f)
        cout << start << " " << right << "\n";
    else {
        left = *max_element(a, a + n);
        cout << left << " " << left << "\n";
    }

    return 0;
}
