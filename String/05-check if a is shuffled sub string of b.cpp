#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    static bool checkEqual(int a[], int b[]) {
        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i]) return false;
        }
        return true;
    }

    static bool checkShuffledSub(string a, string b) {
        if (a.size() > b.size()) swap(a, b);

        int cntMain[26] = {0};
        int cntCurr[26] = {0};
        int i = 0;

        for (char ch : a) {
            cntMain[ch - 'A']++;
            cntCurr[b[i++] - 'A']++;
        }

        if (checkEqual(cntMain, cntCurr)) return true;

        for (int i = a.size(); i < b.size(); i++) {
            cntCurr[b[i] - 'A']++;
            cntCurr[b[i - a.size()] - 'A']--;

            if (checkEqual(cntMain, cntCurr)) return true;
        }

        return false;
    }
};

int main() {
    string a = "BACDGABCDA";
    string b = "ABCD";
    if (Solution::checkShuffledSub(a, b))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}