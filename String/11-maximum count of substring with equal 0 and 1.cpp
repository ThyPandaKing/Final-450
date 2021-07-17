#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int equal_sub_count(string S) {
        int cnt = 0;

        int one = 0, zero = 0;

        for (char i : S) {
            one += i == '1';
            zero += i == '0';

            if (one == zero) cnt++;
        }
        return cnt;
    }
};


int main(){
  Solution ob;

  cout << ob.equal_sub_count("01010011001011");
}