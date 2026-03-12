#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;

        string s = to_string(n);
        int digits = s.size();
        int firstDigit = s[0] - '0';

        cout << 9 * (digits - 1) + firstDigit << '\n';
    }
    return 0;
}
