#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<string> find_permutation(string S) {
        vector<string> ans;
        if (S.size() == 1) {
            ans.push_back(S);
            return ans;
        }

        for (int i = 0; i < S.size(); i++) {
            string temp = S.substr(0, i);
            temp += S.substr(i + 1);
            //  cout<<temp<<"\n";
            vector<string> forThis = find_permutation(temp);

            for (auto k : forThis) {
                ans.push_back(S[i] + k);
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};
