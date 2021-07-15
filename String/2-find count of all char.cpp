#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    void reverseString(string a) {
        map<char, int> mp;
        for (char ch : a) {
            mp[ch]++;
        }

        for (auto it : mp) {
            cout << it.first << ", count = " << it.second << "\n";
        }
    }
};