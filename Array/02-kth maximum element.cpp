#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int kthSmallest(int a[], int l, int r, int k) {
        if (k > 0 && k <= r - l + 1) {
            int rnd = l + rand() % (r - l + 1);
            int i = l;
            swap(a[r], a[rnd]);

            for (int j = l; j < r; j++) {
                if (a[j] < a[r]) {
                    swap(a[i], a[j]);
                    i++;
                }
            }

            swap(a[r], a[i]);

            if (k - 1 == i - l) {
                return a[i];
            } else if (k - 1 < i - l) {
                return kthSmallest(a, l, i - 1, k);
            } else {
                return kthSmallest(a, i + 1, r, k - i + l - 1);
            }
        }
        return INT_MAX;
    }
};

int main() {
    int test_case = 1;

    while (test_case--) {
        int number_of_elements;
        cin >> number_of_elements;
        int a[number_of_elements];

        for (int i = 0; i < number_of_elements; i++) cin >> a[i];

        int k;
        cin >> k;
        Solution ob;
        cout << ob.kthSmallest(a, 0, number_of_elements - 1, k) << endl;
    }
    return 0;
}