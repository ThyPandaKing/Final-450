#include <bits/stdc++.h>

using namespace std;

int main() {
    while (1) {
        int n;
        cin >> n;
        if (n == 0) return 0;
        vector<pair<int, int>> a(n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            sum += a[i].first;
            a[i].second = sum;
        }
        int m;
        cin >> m;
        vector<pair<int, int>> b(m);
        sum = 0;
        for (int i = 0; i < m; i++) {
            cin >> b[i].first;
            sum += b[i].first;
            b[i].second = sum;
        }

        int last_a = 0, last_b = 0;

        int i = 0, j = 0;
        long long int ans = 0;

        while (i < n && j < m) {
                if (a[i].first < b[j].first) {
                    i++;
                } else if (a[i].first > b[j].first) {
                    j++;
                } else {
                    int s1 = a[i].second - last_a;
                    int s2 = b[j].second - last_b;

                    ans += max(s1, s2);
                    last_a = a[i].second;
                    last_b = b[j].second;
                    i++,j++;
                }
            
        }
        ans += max(a[n-1].second - last_a , b[m-1].second - last_b);
        cout<<ans<<"\n";
    }
}