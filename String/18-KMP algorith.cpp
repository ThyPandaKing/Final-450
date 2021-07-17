#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    static void find_substring(string txt, string patt) {
        int n = txt.size(), m = patt.size();

        vector<int> lps_arr = lps(patt);

        int i = 0, j = 0;

        while (i < n) {
            if (txt[i] == patt[j]) {
                i++;
                j++;
            } else if (j == m) {
                cout << "Pattern found: " << i - j << "\n";
                j = lps_arr[j - 1];
            } else {
                if (j > 0)
                    j = lps_arr[j - 1];
                else
                    i++;
            }
        }
        if (j == m) {
            cout << "Pattern found: " << i - j << "\n";
        }
    }

    static vector<int> lps(string s) {
        int n = s.size(), j = 0;

        vector<int> dp(n, 0);

        for (int i = 1; i < n; i++) {
            if (s[i] == s[j]) {
                dp[i] = j + 1;
                j++;
            } else {
                if (j == 0)
                    dp[i] = 0;
                else {
                    j = dp[j - 1];
                    i--;
                }
            }
        }

        return dp;
    }
};

int main() {
    string a, b;
    cin >> a >> b;

    Solution::find_substring(a, b);
}