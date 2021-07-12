#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int findLongestConseqSubseq(int arr[], int N) {
        sort(arr, arr + N);

        int mx = 1, curr = 1, last = arr[0];

        for (int i = 1; i < N; i++) {
            if (last + 1 == arr[i] || last == arr[i]) {
                if (last + 1 == arr[i]) curr++;
                last = arr[i];
            } else {
                mx = max(curr, mx);
                curr = 1;
                last = arr[i];
            }
        }
        return max(curr, mx);
    }
};

int main() {
    int t, n, i, a[100001];
    cin >> t;
    while (t--) {
        cin >> n;
        for (i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        cout << obj.findLongestConseqSubseq(a, n) << endl;
    }

    return 0;
}