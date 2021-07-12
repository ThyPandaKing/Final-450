#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void merge(int arr1[], int arr2[], int n, int m) {
        int first = 0, second = 0, k = n - 1;

        while (first <= k && second < m) {
            if (arr1[first] < arr2[second]) {
                first++;
            } else {
                swap(arr2[second++], arr1[k--]);
            }
        }
        sort(arr1, arr1 + n);
        sort(arr2, arr2 + m);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);
        for (i = 0; i < n; i++) {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++) {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}