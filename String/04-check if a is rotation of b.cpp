#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    bool checkRotation(string a, string b) {
        if (a.size() != b.size()) return false;

        string temp = a + a;
        // now b must be sub string of a
        return temp.find(b) != string::npos;
    }
};