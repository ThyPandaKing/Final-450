#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    const int mod = 1000000007;

    int countFriendsPairings(int n) {
        long a1 = 1, a2 = 1;

        for (int i = 2; i <= n; i++) {
            int temp = a2;

            a2 = (a2 % mod + ((i - 1) % mod * a1 % mod) % mod) % mod;
            a1 = temp;

            // cout<<a1<<" "<<a2<<"\n";
        }

        return (a2) % mod;
    }
};
