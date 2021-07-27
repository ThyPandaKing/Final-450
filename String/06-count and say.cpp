#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }

        string last = countAndSay(n - 1);

        string ans = "";

        for (int i = 0; i < last.size();) {
            int cnt = 0, ele = last[i];

            while (i < last.size() && ele == last[i]) cnt++, i++;

            ans += to_string(cnt);
            ans += to_string(ele - '0');
        }
        // cout << ans << " " << n << "\n";

        return ans;
    }
};