#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int inSequence(int A, int B, int C) {
        if (C > 0) {
            if ((B - A) % C == 0) {
                if (B >= A)
                    return 1;
                else
                    return 0;
            } else {
                return 0;
            }
        } else if (C < 0) {
            if ((B - A) % C == 0) {
                if (B <= A)
                    return 1;
                else
                    return 0;
            } else {
                return 0;
            }
        } else
            return A == B;
    }
};