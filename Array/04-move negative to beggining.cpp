#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void sort(int a[], int n) {
      int low=n-1;

      for(int i=0;i<low;i++){
        if(a[i] > 0){
          swap(a[i],a[low--]);
          i--;
        }
      }

    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        Solution ob;
        ob.sort(a, n);

        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}