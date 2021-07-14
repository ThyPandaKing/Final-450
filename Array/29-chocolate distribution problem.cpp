#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define ul unsigned long long
#define vi vector<ll int>
#define pb push_back
#define mod2 998244353
#define pi 3.1415926535
#define phi 1.61803
#define point(n) fixed << setprecision(n)
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ff first
#define ss second

int main() {
    fast;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], k, i, mn = INT_MAX;
        for (i = 0; i < n; i++) cin >> a[i];
        cin >> k;
        sort(a, a + n);
        for (i = k - 1; i < n; i++) {
            mn = min(mn, a[i] - a[i - k + 1]);
        }
        cout << mn << "\n";
    }
}
