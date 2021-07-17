#include <bits/stdc++.h>
using namespace std;

int romanToDecimal(string &);

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << romanToDecimal(s) << endl;
    }
}

int romanToDecimal(string &str) {
    int value = 0;

    map<char, int> mp;

    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;

    for (int i = 0; i < str.size(); i++) {
        if (i + 1 < str.size()) {
            if (mp[str[i + 1]] > mp[str[i]]) {
                value += mp[str[i + 1]] - mp[str[i]];
                i++;
            } else {
                value += mp[str[i]];
            }
        } else {
            value += mp[str[i]];
        }
    }
    return value;
}