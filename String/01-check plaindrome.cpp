#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int isPalindrome(string S) {
        int i = 0, j = S.size() - 1;

        while (i < j) {
            if (S[i] == S[j])
                i++, j--;
            else
                return 0;
        }
        return 1;
    }
};