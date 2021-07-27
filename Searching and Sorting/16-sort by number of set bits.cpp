#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
        void sortBySetBitCount(int arr[], int n) {
        // implement merge sort

        int *temp = mergeSort(arr, 0, n - 1);

        for (int i = 0; i < n; i++) arr[i] = temp[n - i - 1];
    }

    int *mergeSort(int arr[], int l, int r) {
        if (l == r) {
            int *merged = new int[r - l + 1];

            merged[0] = arr[l];

            return merged;
        }

        int mid = l + (r - l) / 2;

        int *left = mergeSort(arr, l, mid);
        int *right = mergeSort(arr, mid + 1, r);

        int *merged = new int[r - l + 1];

        int i = 0, j = 0, k = 0;

        while (i < (mid - l + 1) && j < (r - mid)) {
            if (__builtin_popcount(left[i]) < __builtin_popcount(right[j])) {
                merged[k++] = left[i++];
            } else {
                merged[k++] = right[j++];
            }
        }

        if (i == (mid - l + 1)) {
            for (; j < (r - mid); j++) merged[k++] = right[j];
        } else {
            for (; i < (mid - l + 1); i++) merged[k++] = left[i];
        }

        delete[] left;
        delete[] right;

        // for(int i=0;i<(r-l+1);i++)cout<<merged[i]<<" ";
        // cout<<"\n";

        return merged;
    }
};