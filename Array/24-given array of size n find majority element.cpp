#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1, num2, cnt1 = 0, cnt2 = 0;

        // moore's voting algorithm

        for (int k : nums) {
            if (k == num1)
                cnt1++;
            else if (k == num2)
                cnt2++;
            else if (cnt1 == 0) {
                cnt1++;
                num1 = k;
            } else if (cnt2 == 0) {
                cnt2++;
                num2 = k;
            } else {
                cnt1--, cnt2--;
            }
        }

        cnt1 = 0, cnt2 = 0;

        for (int k : nums) {
            if (k == num1) cnt1++;
            if (k == num2) cnt2++;
        }
        vector<int> ans;
        if (cnt1 > nums.size() / 3) ans.push_back(num1);
        if (cnt2 > nums.size() / 3) ans.push_back(num2);
        return ans;
    }
};