#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    string longestPalin(string a) {
        string ans;

        for (int i = 0; i < a.size(); i++) {
            // assume i is mid point of palindrome

            // check for odd length
            int j = i - 1, k = i + 1;
            string tempStr;

            while (j >= 0 && k < a.size() && a[j] == a[k]) j--, k++;

            if (k - j - 1 > ans.size()) {
                ans = "";

                for (int id = j + 1; id <= k - 1; id++) ans += a[id];
            }

            // cout<<ans<<" odd\n";
            // check for even length

            j = i, k = i + 1;

            while (j >= 0 && k < a.size() && a[j] == a[k]) j--, k++;

            if (k - j - 1 > ans.size()) {
                ans = "";

                for (int id = j + 1; id <= k - 1; id++) ans += a[id];
            }

            // cout<<ans<<" even\n";
        }

        return ans;
    }
};
