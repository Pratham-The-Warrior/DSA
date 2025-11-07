/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

string subtractStrings(string a, string b)
{
    int n1 = a.size(), n2 = b.size();
    int carry = 0;
    string result;

    for (int i = 0; i < n1; i++)
    {
        int d1 = a[n1 - 1 - i] - '0';
        int d2 = (i < n2) ? b[n2 - 1 - i] - '0' : 0;
        int diff = d1 - d2 - carry;
        if (diff < 0)
            diff += 10, carry = 1;
        else
            carry = 0;
        result.push_back(diff + '0');
    }

    while (result.size() > 1 && result.back() == '0')
        result.pop_back();

    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
    }

    return 0;
}