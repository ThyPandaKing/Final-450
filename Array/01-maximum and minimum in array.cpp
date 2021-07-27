#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Tournament methond, find max,min in both half, compare them and return
 *  accordingly
 *
 * @param a array
 * @param n
 * @return pair<int,int>
 */

pair<int, int> find_max_min(int a[], int low, int high) {
    if (high - low < 2) {
        if (high == low) {
            return {a[low], a[high]};
        } else {
            return {max(a[low], a[high]), min(a[low], a[high])};
        }
    }

    int mid = low + (high - low) / 2;

    pair<int, int> fromFirstHalf = find_max_min(a, low, mid);
    pair<int, int> fromSecondHalf = find_max_min(a, mid + 1, high);

    if (fromFirstHalf.first > fromSecondHalf.first) {
        return {fromFirstHalf.first,
                min(fromFirstHalf.second, fromSecondHalf.second)};
    } else {
        return {fromSecondHalf.first,
                min(fromFirstHalf.second, fromSecondHalf.second)};
    }
}

int main() {
    int n;
    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++) cin >> a[i];

    pair<int, int> mx_mn = find_max_min(a, 0, n - 1);

    cout << mx_mn.first << " " << mx_mn.second << "\n";

    return 0;
}
