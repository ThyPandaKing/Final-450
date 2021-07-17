// C++ program for getting minimum character to be
// added at front to make string palindrome
#include <bits/stdc++.h>
using namespace std;

// returns vector lps for given string str
int computeLPS(string str) {
    int M = str.length();
    vector<int> lps(M);
    lps[0] = 0;

    int i = 1, j = 0;

    while (i < M) {
        if (str[i] == str[j]) {
            lps[i] = j;
            i++, j++;
        } else {
            if (j > 0)
                j = lps[j - 1];
            else
                j = 0, i++;
        }
    }

    for (int k : lps) cout << k << " ";

    cout << endl;

    return lps[M - 1];
}

// Method returns minimum character to be added at
// front to make string palindrome
int getMinCharToAddedToMakeStringPalindrome(string str) {
    string temp = str;

    reverse(str.begin(), str.end());

    temp += str;

    int toSubtract = computeLPS(temp);

    return str.size() - toSubtract - 1;
}

// Driver program to test above functions
int main() {
    string str = "ACECAA";

    cout << getMinCharToAddedToMakeStringPalindrome(str);
    return 0;
}
