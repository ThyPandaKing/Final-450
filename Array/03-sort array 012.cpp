#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void sort012(int a[], int n) {
        int low = 0, mid = 0, high = n - 1;

        // 0-low -> all 0's
        // low-mid -> all 1's
        // mid-high -> unknown
        // high-n -> all 2's

        while (mid <= high) {
            switch (a[mid]) {
                case 0:
                    swap(a[mid++], a[low++]);
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(a[mid], a[high--]);
                    break;
            }
        }
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}