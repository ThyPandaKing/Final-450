#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums,
                                            int n) {
        vector<long long int> ans(n), indx;

        long long int prod = 1;

        for (auto k : nums) {
            if (k)
                prod *= k;
            else
                indx.push_back(k);
        }

        for (int i = 0; i < n; i++) {
            if (nums[i]) {
                ans[i] = indx.size() ? 0 : prod / nums[i];
            } else {
                if (indx.size() == 1)
                    ans[i] = prod;
                else
                    ans[i] = 0;
            }
        }
        return ans;
        // code here
    }
};