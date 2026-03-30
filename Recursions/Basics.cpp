#include <bits/stdc++.h>
using namespace std;

void reverseString(string s)
{
    if (s.empty())
        return; // base case

    reverseString(s.substr(1));
    cout << s[0];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    reverseString(s);
}
