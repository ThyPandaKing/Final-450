#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string a;
        cin >> a;
        int i = 0;
        string res;

        priority_queue<pair<int, char>> pq;

        int cnt[26] = {0};

        for (char k : a) {
            cnt[k - 'a']++;
        }

        pair<int, char> last = {-1, '-'};

        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 0) pq.push({cnt[i], i + 'a'});
        }

        while (!pq.empty()) {
            auto tp = pq.top();
            pq.pop();

            res += tp.second;

            if (last.first > 0) {
                pq.push(last);
            }

            last = {tp.first - 1, tp.second};
        }
        // cout<<res<<" "<<a<<"\n";
        if (res.size() == a.size()) {
            cout << "1\n";
        } else {
            cout << "0\n";
        }
    }

    return 0;
}

/**
 * @brief for O(n) solution, simply fill even position first with max freq,
 *  then fill odd
 *
 * string res(n, ' ');

    int ind = 0;
    // filling the most frequently occuring char in the even
    // indices
    while (maxCount) {
        res[ind] = ch_max;
        ind = ind + 2;
        maxCount--;
    }
    count[ch_max - 'a'] = 0;

    // now filling the other Chars, first filling the even
    // positions and then the odd positions
    for (int i = 0; i < 26; i++) {
        while (count[i] > 0) {
            ind = (ind >= n) ? 1 : ind;
            res[ind] = 'a' + i;
            ind += 2;
            count[i]--;
        }
    }
 */
