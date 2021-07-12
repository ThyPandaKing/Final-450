#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        int tor = nums[0], hare = nums[0];

        // assume the array to be connected as
        // arr -> 2 6 4 1 3 1 5
        // indx ->0 1 2 3 4 5 6

        // connected, we can directly find answer by tortoise hare algo.

        do {
            tor = nums[tor];
            hare = nums[nums[hare]];
        } while (tor != hare);

        tor = nums[0];

        while (tor != hare) {
            tor = nums[tor];
            hare = nums[hare];
        }

        // cout<<hare<<"\n";
        return hare;
    }
};