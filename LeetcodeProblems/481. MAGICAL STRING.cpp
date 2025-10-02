#include <bits/stdc++.h>
using namespace std;

int magicalString(int n)
{
    if (n == 0)
        return 0;
    if (n <= 3)
        return 1; // "122" has one '1'

    string s = "122";
    int countOnes = 1; // initial '1'
    int i = 2;         // pointer in the string for read

    while ((int)s.size() < n)
    {
        int repeat = s[i] - '0';                       // get number of times to repeat
        char nextChar = (s.back() == '1') ? '2' : '1'; // alternate
        for (int j = 0; j < repeat; j++)
        {
            s += nextChar;
            if (nextChar == '1' && s.size() <= n)
                countOnes++;
        }
        i++;
    }

    return countOnes;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << magicalString(n) << "\n";
    }

    return 0;
}
