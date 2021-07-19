#include <bits/stdc++.h>

using namespace std;

bool is_valid(string a) {
    vector<string> all;
    string temp;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '.') {
            all.push_back(temp);
            temp = "";
        } else {
            temp += a[i];
        }
    }
    all.push_back(temp);

    for (string str : all) {
        if (str.length() > 3 || stoi(str) > 255 || stoi(str) < 0 ||
            (str.length() > 1 && str[0] == '0'))
            return false;
    }

    

    return true;
}

void find_all(string a) {
    if (a.size() > 12 || a.size() < 4) {
        cout << "[]\n";
        return;
    }
    // this is an O(n^3) approach, for O(n) approach we need dp

    // check all substrings
    int n = a.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                string to_check;
                to_check = a.substr(0, i + 1) + "." + a.substr(i + 1, j  - i) +
                           "." + a.substr(j + 1, k  - j) + "." + a.substr(k + 1);


                if (is_valid(to_check)) {
                    cout << "Valid part of IP: " << to_check << "\n";
                }
            }
        }
    }
}

int main() {
    string a = "25525511135";
    string b = "25515011535";

    cout<<"For a:" << a << " -> {\n";
    find_all(a);

    cout << "}\nFor b:" << b << " -> {\n";
    find_all(b);

    cout<<"}\n";
}