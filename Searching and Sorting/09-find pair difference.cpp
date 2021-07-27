// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// sort and 2 pointer

bool findPair(int arr[], int size, int n) {
    sort(arr, arr + size);

    int i = 0, j = 1;

    while (j < size) {
        int diff = arr[j] - arr[i];

        if (diff == n) {
            return true;
        } else if (diff > n) {
            i++;
        } else {
            j++;
        }
    }

    return false;
}