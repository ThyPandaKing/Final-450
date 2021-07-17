#include <bits/stdc++.h>
using namespace std;

class Solution {
    char reverse(char ch) {
        if (ch == ')')
            return '(';
        else if (ch == '}')
            return '{';
        else
            return '[';
    }

   public:
    bool isPar(string x) {
        stack<char> st;

        for (int i = 0; i < x.size(); i++) {
            if (x[i] == '}' || x[i] == ')' || x[i] == ']') {
                if (st.empty())
                    return false;
                else {
                    if (st.top() == reverse(x[i])) {
                        st.pop();
                    } else
                        return false;
                }
            } else {
                st.push(x[i]);
            }
        }
        return st.empty();
    }
};