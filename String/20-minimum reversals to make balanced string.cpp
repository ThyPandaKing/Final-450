#include <bits/stdc++.h>
using namespace std;

int countRev(string s);
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << countRev(s) << '\n';
    }
}

int countRev(string s) {
    if (s.size() % 2) return -1;

    stack<char> st;
    int cnt = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '{')
            st.push('{');
        else {
            if (st.size()) {
                st.pop();
            } else {
                cnt++;
            }
        }
    }

    return ceil(cnt / 2.0) + ceil(st.size() / 2.0);
}