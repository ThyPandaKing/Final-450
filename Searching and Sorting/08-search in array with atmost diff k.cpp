#include <bits/stdc++.h>
using namespace std;
int find(int a[], int n, int x, int k) {
    int i = 0;

    while (i < n) {
        if (a[i] == x) {
            return i;
        }

        i += max(1, abs(x - a[i]) / k);
    }
    return -1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x, k;
        cin >> n >> x >> k;
        int arr[n], i;
        for (i = 0; i < n; i++) cin >> arr[i];

        int ans = find(arr, n, x, k);
        cout << ans << endl;
    }
    return 0;
}
