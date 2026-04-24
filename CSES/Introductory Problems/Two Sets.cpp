/*-------------------------------------------------------------
   NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
---------------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    ll sum = n * (n + 1) / 2;

    vector<ll> num(n);

    for (int i = 0; i < n; i++)
    {
        num[i] = i + 1;
    }

    if (sum & 1)
    {
        cout << "NO";
        return 0;
    }

    cout << "YES" << endl;
    vector<int> a, b;

    if (n % 4 == 0)
    {
        for (int i = 1; i <= n; i += 4)
        {
            a.push_back(i);
            a.push_back(i + 3);
            b.push_back(i + 1);
            b.push_back(i + 2);
        }
    }

    else
    {
        a.push_back(1);
        a.push_back(2);
        b.push_back(3);

        for (int i = 4; i <= n; i += 4)
        {
            a.push_back(i);
            a.push_back(i + 3);
            b.push_back(i + 1);
            b.push_back(i + 2);
        }
    }

    cout << a.size() << endl;
    for (auto x : a)
        cout << x << " ";
    cout << endl;
    cout << b.size() << endl;
    for (auto x : b)
        cout << x << " ";
    cout << endl;

    return 0;
}