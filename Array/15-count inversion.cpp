#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    long long int ans = 0;

    long long int* myMergeSort(long long int a[], long long int l,
                               long long int r) {
        if (r <= l) {
            long long int* temp = new long long int[1];

            temp[0] = a[l];

            return temp;
        }

        int mid = l + (r - l) / 2;

        long long int* first = myMergeSort(a, l, mid);
        long long int* second = myMergeSort(a, mid + 1, r);

        long long int* answerArr = new long long int[r - l + 1];

        long long int i = 0, j = 0, k = 0;

        while (i < (mid - l + 1) || j < (r - mid)) {
            if (i < (mid - l + 1) && j < (r - mid)) {
                if (first[i] <= second[j]) {
                    answerArr[k++] = first[i++];
                } else {
                    answerArr[k++] = second[j++];
                    ans += (mid - l + 1 - i);
                }
            } else if (j >= (r - mid)) {
                answerArr[k++] = first[i++];
            } else {
                answerArr[k++] = second[j++];
            }
        }

        delete[] first;
        delete[] second;

        return answerArr;
    }

    long long int inversionCount(long long arr[], long long N) {
        // using merge method of merge sort to find the answer.

        arr = myMergeSort(arr, 0, N - 1);
        return ans;
    }
};

int main() {
    long long T;
    cin >> T;

    while (T--) {
        long long N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A, N) << endl;
    }

    return 0;
}