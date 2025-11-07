/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

#define d 256 // Number of characters in the input alphabet
#define q 101 // A prime number for modulus (helps reduce collisions)

// Rabin–Karp pattern searching function
void rabinKarpSearch(const string &pattern, const string &text)
{
    int m = pattern.length();
    int n = text.length();
    int i, j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for text
    int h = 1;

    // The value of h would be "pow(d, m-1) % q"
    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Calculate the hash value of pattern and first window of text
    for (i = 0; i < m; i++)
    {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide the pattern over the text one character at a time
    for (i = 0; i <= n - m; i++)
    {
        // Check if hash values match
        if (p == t)
        {
            // If hash matches, check characters one by one
            for (j = 0; j < m; j++)
            {
                if (text[i + j] != pattern[j])
                    break;
            }
            if (j == m)
                cout << "Pattern found at index " << i << endl;
        }

        // Calculate hash value for next window of text:
        // Remove leading character, add trailing character
        if (i < n - m)
        {
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            // We might get a negative value of t, convert it to positive
            if (t < 0)
                t = (t + q);
        }
    }
}

// Example usage
int main()
{
    string text = "GEEKS FOR GEEKS";
    string pattern = "GEEK";

    rabinKarpSearch(pattern, text);

    return 0;
}
