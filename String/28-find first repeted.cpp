#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string secFrequent(string arr[], int n) {
        set<string> mp;

        for (int i = 0; i < n; i++) {
            if (mp.find(arr[i]) == mp.end())
                mp.insert(arr[i]);
            else
                return arr[i];
        }
    }
};
