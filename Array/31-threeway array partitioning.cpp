// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>

#include <unordered_map>
using namespace std;

class Solution {
   public:
    void threeWayPartition(vector<int>& arr, int a, int b) {
        int i = 0, j = arr.size() - 1, k = 0;

        // i will start, j will be in end, 0<->i < a && j<->n-1 > b, k is to
        // iterate

        for (k = 0; k <= j;) {
            if (arr[k] < a) {
                swap(arr[i++], arr[k++]);
            } else if (arr[k] > b) {
                swap(arr[j--], arr[k]);
            } else {
                k++;
            }
        }
    }
};