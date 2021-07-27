#include <bits/stdc++.h>
using namespace std;
vector<int> find(int a[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n], i;
        for (i = 0; i < n; i++) cin >> arr[i];
        vector<int> ans;
        ans = find(arr, n, x);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}

int first(int arr[], int n, int x) {
    int first = -1;

    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x) {
            first = mid;
            right = mid - 1;

        } else if (arr[mid] > x) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return first;
}

int last(int arr[], int n, int x) {
    int last = -1;

    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x) {
            last = mid;
            left = mid + 1;

        } else if (arr[mid] > x) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return last;
}

vector<int> find(int arr[], int n, int x) {
    return {first(arr, n, x), last(arr, n, x)};
}