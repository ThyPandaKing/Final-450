#include <string.h>

#include <iostream>

using namespace std;
#define MAX_CHARS 256

#include <bits/stdc++.h>
class Solution {
   public:
    bool areIsomorphic(string str1, string str2) {
        if (str1.size() != str2.size()) return false;

        map<char, char> mp;

        for (int i = 0; i < str2.size(); i++) {
            if (mp[str1[i]]) {
                if (mp[str1[i]] != str2[i]) {
                    return false;
                }
            } else {
                mp[str1[i]] = str2[i];
            }
        }
        mp.clear();
        for (int i = 0; i < str1.size(); i++) {
            if (mp[str2[i]]) {
                if (mp[str2[i]] != str1[i]) {
                    return false;
                }
            } else {
                mp[str2[i]] = str1[i];
            }
        }

        return true;
    }
};