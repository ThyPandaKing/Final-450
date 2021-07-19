#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    string S;
    cin >> S;

    int ans = 0, i, n = S.size();
    char need = '0';

    for (i = 0; i < n; i++) {
        if (S[i] != need) {
            ans++;
        }

        need = need == '0' ? '1' : '0';
    }

    // assume 10
    need = '1';

    int temp = 0;

    for (i = 0; i < n; i++) {
        if (S[i] != need) {
            temp++;
        }

        need = need == '0' ? '1' : '0';
    }

    cout << min(ans, temp);
    return 0;
}