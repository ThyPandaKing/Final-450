#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int> > fourSum(vector<int> &a, int k) {
        sort(a.begin(), a.end());
        int n = a.size();
        vector<vector<int> > res;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int left = j + 1;
                int right = n - 1;
                while (left < right) {
                    int s = a[i] + a[j] + a[left] + a[right];
                    if (s == k) {
                        vector<int> v;
                        v.push_back(a[i]);
                        v.push_back(a[j]);
                        v.push_back(a[left]);
                        v.push_back(a[right]);
                        res.push_back(v);
                    }
                    if (s > k) {
                        do {
                            --right;
                        } while (a[right + 1] == a[right] && right > left);
                    } else {
                        do {
                            ++left;
                        } while (a[left] == a[left - 1] && right > left);
                    }
                }
                while (j + 1 < n && a[j] == a[j + 1]) ++j;
            }
            while (i + 1 < n && a[i] == a[i + 1]) ++i;
        }
        return res;
    }
};