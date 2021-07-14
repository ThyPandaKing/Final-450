#include <bits/stdc++.h>

using namespace std;

int operation_palindrome(int a[], int n) {
    int i = 0, j = n - 1;
    int ans = 0;

    while (i < j) {
        if (a[i] == a[j]) {
            i++, j--;
        } else if (a[i] > a[j]) {
            a[j - 1] += a[j];
            ans++;
            j--;
        } else {
            a[i + 1] += a[i];
            ans++;
            i++;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++) cin >> a[i];

    cout << operation_palindrome(a, n) << endl;
}