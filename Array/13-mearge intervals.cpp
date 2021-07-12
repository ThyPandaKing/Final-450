
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        for (int i = 0; i < intervals.size();) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            while (i < intervals.size() && end >= intervals[i][0]) {
                end = max(end, intervals[i][1]);
                i++;
            }

            ans.push_back({start, end});
        }

        return ans;
    }
};