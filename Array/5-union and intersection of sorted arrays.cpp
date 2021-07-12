#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Function to return the count of number of elements in union of two
    // arrays.
    int doUnion(int a[], int n, int b[], int m) {
        int ans[n + m] = {0};
        sort(a, a + n);
        sort(b, b + m);

        int indx = 1;

        ans[0] = a[0];

        for (int i = 1; i < n; i++) {
            if (a[i] != a[i - 1]) ans[indx++] = a[i];
        }

        for (int j = 0; j < m; j++) {
            if (j == 0 || j && b[j] != b[j - 1]) {
                int l = 0, r = n - 1;
                bool set = true;

                while (l <= r) {
                    int mid = l + (r - l) / 2;

                    if (a[mid] == b[j]) {
                        set = false;
                        break;
                    } else if (a[mid] > b[j])
                        r = mid - 1;
                    else
                        l = mid + 1;
                }

                if (set) {
                    ans[indx++] = b[j];
                }
            }
        }

        return indx;
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n], b[m];

        for (int i = 0; i < n; i++) cin >> a[i];

        for (int i = 0; i < m; i++) cin >> b[i];
        Solution ob;
        cout << ob.doUnion(a, n, b, m) << endl;
    }

    return 0;
}