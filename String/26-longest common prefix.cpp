#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    string longestCommonPrefix(vector<string>& v) {
        int i, ans = 0, ct = INT_MAX, f = 0;
        if (v.size() == 0) {
            return "";
        }
        if (v.size() == 1) {
            return v[0];
        }

        for (i = 0; i < v.size(); i++) {
            ct = min(ct, (int)v[i].size());
        }

        for (i = 0; i < ct; i++) {
            for (int j = 1; j < v.size(); j++) {
                if (v[j][i] == v[j - 1][i]) {
                } else {
                    f = 1;
                    break;
                }
            }

            if (f == 0)
                ans++;
            else
                break;
        }

        string ansString = "";
        for (i = 0; i < ans; i++) {
            ansString += v[0][i];
        }
        return ansString;
    }
};