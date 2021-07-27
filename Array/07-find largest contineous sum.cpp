#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // arr: input array
    // n: size of array
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(int arr[], int n) {
        int ans = INT_MIN;
        int temp = 0;

        for (int i = 0; i < n; i++) {
            temp += arr[i];

            if (temp <= 0) {
                temp = 0;
            } else {
                ans = max(ans, temp);
            }
        }

        if (ans == INT_MIN) ans = *max_element(arr, arr + n);

        return ans;
    }
};

int main() {
    int t, n;

    cin >> t;    // input testcases
    while (t--)  // while testcases exist
    {
        cin >> n;  // input size of array

        int a[n];

        for (int i = 0; i < n; i++) cin >> a[i];  // inputting elements of array

        Solution ob;

        cout << ob.maxSubarraySum(a, n) << endl;
    }
}