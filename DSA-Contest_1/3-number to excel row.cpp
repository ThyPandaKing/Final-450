#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long int n;
        cin >> n;

        string ans;

        while (n > 0) {
            n--;
            ans += ('A' + n % 26);

            n /= 26;
        }

        reverse(ans.begin(), ans.end());
        cout << ans << "\n";
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
