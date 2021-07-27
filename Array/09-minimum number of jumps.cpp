#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minJumps(int arr[], int n) {
        int maxReach = arr[0]; // it has the maximum index/place where we can reach
        int steps = arr[0]; // it has the remaining steps we can take
        int jumps = 1; // it has our answer i.e. jumps to reach that place

        if (n == 1)
            return 0;
        else if (arr[0] == 0)
            return -1;

        for (int i = 1; i < n; i++) {

            if(steps <= 0)return -1; // incase we can't move forward

            if (i == n - 1) {
                return jumps;
            }

            maxReach = max(maxReach, i + arr[i]);

            steps--;

            if (steps == 0) {
              // if steps is 0, then we know we have to jump, and new possible steps 
              // will be maxReach-i
                jumps++;
                steps = maxReach - i;
            }
        }

        return -1;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i, j;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.minJumps(arr, n) << endl;
    }
    return 0;
}