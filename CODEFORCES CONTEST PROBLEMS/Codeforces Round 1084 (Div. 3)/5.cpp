/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int prime_check(int x)
{
    set<int> s;

    for (int i = 2; i * i <= x; i++)
    {
        while (x % i == 0)
        {
            s.insert(i);
            x /= i;
        }
    }

    if (x > 1)
    {
        s.insert(x);
    }

    if (s.size() > 1)
        return -1;
    if (s.size() == 0)
        return 1;

    return *s.begin();
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
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++)
        {
            b[i] = prime_check(a[i]);
        }

        if (is_sorted(a.begin(), a.end()))
        {
            cout << "Bob" << endl;
        }
        else if (*min_element(b.begin(), b.end()) == -1)
        {
            cout << "Alice" << endl; // alice can make a move and win instantly
        }
        else if (is_sorted(b.begin(), b.end()))
        {
            cout << "Bob" << endl;
        }
        else
        {
            cout << "Alice" << endl;
        }
    }

    return 0;
}