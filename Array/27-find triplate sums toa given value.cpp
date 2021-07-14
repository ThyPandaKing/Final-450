#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // two pointers and sorting
    bool find3Numbers(int a[], int n, int X) {
        sort(a, a + n);

        int i = 0, j = n - 1, k;

        for (k = 1; k < n - 1; k++) {
            i = 0, j = n - 1;

            while (i < k && j > k) {
                if (X > a[i] + a[j] + a[k]) {
                    i++;
                } else if (X == a[i] + a[j] + a[k])
                    return 1;
                else
                    j--;
            }
        }

        return 0;
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, X;
        cin >> n >> X;
        int i, A[n];
        for (i = 0; i < n; i++) cin >> A[i];
        Solution ob;
        cout << ob.find3Numbers(A, n, X) << endl;
    }
}