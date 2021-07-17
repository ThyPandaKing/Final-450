#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> nextPermutation(int n, vector<int> a) {
        int i = n - 1;

        while (i > 0 && a[i] < a[i - 1]) i--;

        if (i == 0) {
            reverse(a.begin(), a.end());
            return a;
        }
        i--;

        for (int j = n - 1; j >= i; j--) {
            if (a[j] > a[i]) {
                // cout << a[i] <<" " << a[j] << "\n";
                swap(a[i], a[j]);
                reverse(a.begin() + i + 1, a.end());
                break;
            }
        }
        return a;
    }
};