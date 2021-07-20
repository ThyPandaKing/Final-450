#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int median(vector<vector<int>> &matrix, int r, int c) {
        // code here
        int end = 2000, start = 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            // search for elements less than mid

            int num_less = 0;

            for (int i = 0; i < r; i++) {
                int left = 0, right = c - 1;
                int indx = 0;

                while (left <= right) {
                    int mid_ele = left + (right - left) / 2;

                    if (matrix[i][mid_ele] <= mid) {
                        indx = mid_ele + 1;  // 0 index means 1 item
                        left = mid_ele + 1;
                    } else {
                        // indx = mid_ele;
                        right = mid_ele - 1;
                    }
                }
                num_less += indx;
            }

            // cout << num_less << " " << mid << "\n";

            if (num_less == (r * c + 1) / 2) {
                end = mid - 1;
            } else if (num_less < (r * c + 1) / 2) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return start;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j) cin >> matrix[i][j];
        Solution obj;
        cout << obj.median(matrix, r, c) << endl;
    }
    return 0;
}