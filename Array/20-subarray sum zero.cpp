#include <bits/stdc++.h>
using namespace std;


class Solution {
   public:
    // Complete this function
    // Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n) {
        map<int, int> mp;
        int sum = 0;
        mp[0]++;
        for (int i = 0; i < n; i++) {
            sum += arr[i];

            if (mp[sum] > 0) {
                return true;
            }

            mp[sum]++;
        }

        return false;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        if (obj.subArrayExists(arr, n))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}