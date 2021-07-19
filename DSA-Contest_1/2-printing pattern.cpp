#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    char a[2 * (n - 1)][2 * (n - 1)];

    for (int i = 0; i < 2 * n - 2; i++) {
        for (int j = 0; j < 2 * n - 2; j++) {
            a[i][j] = ' ';
        }
    }

    int i = n - 1, j = 0, k = n - 1;

    while (j < 2 * (n - 1)) {
        a[j][i] = '*';
        a[j][k] = '*';

        j++;

        if (j > n - 1) {
            k--;
            i++;
        } else if (j < n - 1) {
            k++;
            i--;
        }
    }

    for (int j = n - 1; j < 2 * n - 3; j++) {
        bool change = false;
        for (int i = 0; i < 2 * n - 2; i++) {
            if (a[j][i] == '*') change = !change;

            if (change) {
                a[j][i] = '*';
            }
        }
    }

    for (int i = 0; i < 2 * n - 2; i++) {
        for (int j = 0; j < 2 * n - 2; j++) {
            cout << a[i][j];
        }
        cout << "\n";
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}