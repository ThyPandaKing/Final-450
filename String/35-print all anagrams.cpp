#include <bits/stdc++.h>

#include <unordered_map>
using namespace std;
vector<vector<string>> Anagrams(vector<string>& string_list);

vector<vector<string>> Anagrams(vector<string>& string_list) {
    map<string, vector<string>> mp;
    vector<vector<string>> anagramList;

    for (string k : string_list) {
        string m = k;
        sort(m.begin(), m.end());

        mp[m].push_back(k);

        // cout<<m<<" "<<k<<"\n";
    }
    // cout<<"\n\n\n";
    for (string k : string_list) {
        string m = k;
        sort(m.begin(), m.end());

        if (mp[m].size()) anagramList.push_back(mp[m]);

        mp[m].clear();
    }
    return anagramList;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i) cin >> string_list[i];
        vector<vector<string>> result = Anagrams(string_list);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result[i].size(); j++) {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}