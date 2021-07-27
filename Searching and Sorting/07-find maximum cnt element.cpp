#include <stdbool.h>
#include <stdio.h>

// Function to find majority element in the array
// a: input array
// size: size of input array
int majorityElement(int a[], int n) {
    int candidate = -1, cnt = 0;

    for (int i = 0; i < n; i++) {
        if (candidate == a[i])
            cnt++;
        else if (cnt == 0) {
            candidate = a[i];
            cnt = 1;
        } else {
            cnt--;
        }
    }

    cnt = 0;

    for (int i = 0; i < n; i++)
        if (a[i] == candidate) cnt++;

    return cnt > n / 2 ? candidate : -1;
}