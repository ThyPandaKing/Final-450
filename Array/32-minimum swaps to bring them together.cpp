#include <bits/stdc++.h>

using namespace std;

int minSwap(int *arr, int n, int k) {
    int cnt = 0, bad = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] <= k) cnt++;
    }

    for (int i = 0; i < cnt; i++)
        if (arr[i] > k) bad++;

    int ans = bad;

    for (int i = 1, j = cnt; j < n; j++, i++) {
        if (arr[i - 1] > k) bad--;

        if (arr[j] > k) bad++;

        ans = min(ans, bad);
    }

    return ans;
}
