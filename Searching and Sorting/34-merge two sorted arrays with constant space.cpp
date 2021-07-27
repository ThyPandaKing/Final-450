#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Function to merge the arrays.
    void merge(long long arr1[], long long arr2[], int n, int m) {
        int gap = (n + m) % 2 == 0 ? (n + m) / 2 : (n + m) / 2 + 1;

        while (gap) {
            int i = 0;

            for (i = 0; i < n + m - gap; i++) {
                if (i >= n) {
                    int idx = i - n;
                    if (arr2[idx] > arr2[idx + gap]) {
                        swap(arr2[idx], arr2[idx + gap]);
                    }
                } else {
                    int id2 = i + gap;
                    if (id2 >= n) {
                        id2 -= n;
                        if (arr1[i] > arr2[id2]) {
                            swap(arr1[i], arr2[id2]);
                        }
                    } else {
                        if (arr1[i] > arr1[id2]) {
                            swap(arr1[i], arr1[id2]);
                        }
                    }
                }
                // for(int j=0;j<n;j++)cout<<arr1[j]<<" ";
                // cout<<"\n";
                // for(int j=0;j<m;j++)cout<<arr2[j]<<" ";
                // cout<<"\n";
            }
            // cout<<"for gap -> "<<gap<<"\n";
            if (gap == 1) break;

            gap = gap % 2 == 0 ? gap / 2 : gap / 2 + 1;
        }
    }
};