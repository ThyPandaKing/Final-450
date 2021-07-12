#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> factorial(int N) {
        vector<int> ans(3001, 0);

        ans[0] = 1;
        int result_size = 1;

        for (int i = 2; i <= N; i++) {
            int add = 0, j = 0;

            for (j = 0; j < result_size; j++) {
                ans[j] = ans[j] * i + add;
                add = ans[j] / 10;
                ans[j] %= 10;
            }
            // cout<<add<<" -> ";
            while (add) {
                ans[result_size] = add % 10;
                add /= 10;
                result_size++;
            }

            // for(int i=0;i<result_size;i++)cout<<ans[i]<<" ";
            // cout<<"\n";
        }

        ans.erase(ans.begin() + result_size, ans.end());
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i];
        }
        cout << endl;
    }
    return 0;
}