#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int sb(int arr[], int n, int x) {
        int i = 0, j = 0;

        int sum = arr[0];
        int len = 1, ans = sum > x ? 1 : INT_MAX;

        while (i < n) {
            // cout<< sum << " " << i << " " << j <<"\n";
            if (sum > x) {
                ans = min(ans, j - i + 1);
                sum -= arr[i++];
            } else {
                if (j < n - 1)
                    sum += arr[++j];
                else
                    break;
            }
        }

        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        cout << obj.sb(a, n, x) << endl;
    }
    return 0;
}