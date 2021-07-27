#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    static void printSubSeq(string a, string b = "") {
        if (a.empty()) {
            cout << b << "\n";
            return;
        }

        // take first element
        printSubSeq(a.substr(1), b + a[0]);

        // don't take it

        printSubSeq(a.substr(1),b);
    }
};

int main() {
    string a = "ABCD";
    Solution::printSubSeq(a);

    return 0;
}