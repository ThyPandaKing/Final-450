/* Following program is a C++ implementation of Rabin Karp
Algorithm given in the CLRS book */
#include <bits/stdc++.h>
using namespace std;

// d is the number of characters in the input alphabet
#define d 256

/**
 * @brief find all occurrence pat in txt
 * 
 * @param pat -> the string which needs to be found
 * @param txt -> the string in which value has to be found
 * @param q -> prime number
 */

void search(char pat[], char txt[], int q) {
    int M = strlen(pat);
    int N = strlen(txt);
    int i, j;
    int pattern_hash_value = 0;  // hash value for pattern
    int text_hash_value = 0;  // hash value for txt
    int h = 1;
    

    // The value of h would be "pow(d, M-1)%q"
    for (i = 0; i < M - 1; i++) h = (h * d) % q;

    // Calculate the hash value of pattern and first
    // window of text
    for (i = 0; i < M; i++) {
        pattern_hash_value = (d * pattern_hash_value + pat[i]) % q;
        text_hash_value = (d * text_hash_value + txt[i]) % q;
    }

    // Slide the pattern over text one by one
    for (i = 0; i <= N - M; i++) {
        // Check the hash values of current window of text
        // and pattern. If the hash values match then only
        // check for characters on by one
        if (pattern_hash_value == text_hash_value) {
            /* Check for characters one by one */
            for (j = 0; j < M; j++) {
                if (txt[i + j] != pat[j]) break;
            }

            // if pattern_hash_value == text_hash_value and pat[0...M-1] = txt[i, i+1, ...i+M-1]
            if (j == M) cout << "Pattern found at index " << i << endl;
        }

        // Calculate hash value for next window of text: Remove
        // leading digit, add trailing digit
        if (i < N - M) {
            text_hash_value = (d * (text_hash_value - txt[i] * h) + txt[i + M]) % q;

            // We might get negative value of text_hash_value, converting it
            // to positive
            if (text_hash_value < 0) text_hash_value = (text_hash_value + q);
        }
    }
}

/* Driver code */
int main() {
    char txt[] = "GEEKS FOR GEEKS";
    char pat[] = "GEEK";

    // A prime number
    int q = 101;

    // Function Call
    search(pat, txt, q);
    return 0;
}
