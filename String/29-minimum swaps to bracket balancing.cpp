#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minimumNumberOfSwaps(string S) {
        int cnt1 = 0, cnt2 = 0;
        int imbalance = 0, ans = 0;

        for (char s : S) {
            if (s == '[') {
                cnt1++;

                if (imbalance > 0) {
                    ans += imbalance;
                    imbalance--;
                }
            } else {
                cnt2++;

                imbalance = cnt2 - cnt1;
            }
        }
        // cout<<cnt1<<" "<<cnt2<<"\n";
        return ans;
    }
};
