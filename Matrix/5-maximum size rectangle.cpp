#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

class Solution {
   public:
    int histogram_area(int a[], int n) {
        vector<int> left(n), right(n);

        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && a[i] <= a[st.top()]) st.pop();

            if (st.empty()) {
                left[i] = -1;
            } else {
                left[i] = st.top();
            }

            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && a[i] <= a[st.top()]) st.pop();

            if (st.empty()) {
                right[i] = n;
            } else {
                right[i] = st.top();
            }

            st.push(i);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            // cout<<left[i] << " "<<right[i]<<"\n";
            ans = max(ans, (right[i] - left[i] - 1) * a[i]);
        }
        return ans;
    }

    int maxArea(int M[MAX][MAX], int n, int m) {
        int arr[n] = {0};
        int ans = 0;

        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                if (M[i][j]) {
                    arr[i]++;
                } else {
                    arr[i] = 0;
                }
            }

            // for(int i=0;i<n;i++)cout<<arr[i]<<" ";

            // cout<<"\n";

            // find largest histograph area

            int area = histogram_area(arr, n);
            // cout<<area<<"\n";

            if (area > ans) ans = area;
        }

        return ans;
    }
};
