#include <bits/stdc++.h>

using namespace std;

// if array is sorted then normal binary search will work
class Solution {
   public:
    vector<int> valueEqualToIndex(int arr[], int n) {
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (arr[i] == i + 1) ans.push_back(i + 1);
        }

        return ans;
    }
};