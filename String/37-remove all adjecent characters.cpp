#include <bits/stdc++.h>
using namespace std;


class Solution {
   public:
    string removeConsecutiveCharacter(string S) {
        stack<char> st;

        for (char k : S) {
            if (st.empty()) {
                st.push(k);
            } else {
                if (st.top() != k) {
                    st.push(k);
                }
            }
        }

        string s;

        while (st.size()) s += st.top(), st.pop();

        reverse(s.begin(), s.end());

        return s;
    }
};
