#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    void rearrange(int arr[], int n) {
        int i = 0, j = 0, k = 0;

        if (n == 1) return;

        vector<int> pos, neg;

        for (int i = 0; i < n; i++) {
            if (arr[i] >= 0)
                pos.push_back(arr[i]);
            else
                neg.push_back(arr[i]);
        }

        while (i < pos.size() && j < neg.size()) {
            arr[k++] = pos[i++];
            if (k < n - 1) arr[k++] = neg[j++];
        }

        if (i < pos.size()) {
            for (; i < pos.size(); i++) arr[k++] = pos[i];
        } else {
            for (; j < neg.size(); j++) arr[k++] = neg[j];
        }
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}