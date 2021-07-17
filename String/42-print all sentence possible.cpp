#include <bits/stdc++.h>

#define MAX 100
#define R 3
#define C 3
using namespace std;

void print_vromi(string arr[R][C], int n, int m, string tillNow = "") {
    if (n == R || m == C) return;

    if (n == R - 1) {
        cout << tillNow + " " + arr[n][m] << "\n";
        return;
    }

    for (int i = 0; i < C; i++) {
        if (arr[n + 1][i] != "")
            print_vromi(arr, n + 1, i, tillNow + " " + arr[n][m]);
    }
}

void print_ans(string arr[R][C]) {
    for (int i = 0; i < C; i++) {
        if (arr[0][i] != "") print_vromi(arr, 0, i);
    }
}

// Driver program to test above functions
int main() {
    string arr[R][C] = {
        {"you", "we"}, {"have", "are"}, {"sleep", "eat", "drink"}};

    print_ans(arr);

    return 0;
}
