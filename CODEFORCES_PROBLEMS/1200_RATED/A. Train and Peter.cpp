#include <bits/stdc++.h>
using namespace std;

bool check(string a, string b, string c)
{
    size_t pos_b = a.find(b);
    if (pos_b == string::npos)
        return false;

    size_t pos_c = a.find(c, pos_b + b.size());
    if (pos_c == string::npos)
        return false;

    return true;
}

int main()
{
    string a, b, c;
    cin >> a >> b >> c;

    bool forward = check(a, b, c);

    reverse(a.begin(), a.end());
    bool backward = check(a, b, c);

    if (forward && backward)
        cout << "both";
    else if (forward)
        cout << "forward";
    else if (backward)
        cout << "backward";
    else
        cout << "fantasy";

    return 0;
}