#include <bits/stdc++.h>
using namespace std;

int get_mex(vector<int> &v)
{
    int n = v.size();
    vector<bool> present(n + 2, false);

    for (int x : v)
    {
        if (x >= 0 && x <= n + 1)
            present[x] = true;
    }

    for (int i = 0; i <= n + 1; i++)
    {
        if (!present[i])
            return i;
    }

    return n + 1;
}

int main()
{

    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }

    int val = get_mex(a);

    if (val == x)
    {
        cout << 0 << endl;
    }
    else if (val < x)
    {
        int cnt = 0;
        for (int i = 0; i <= x - 1; i++)
        {
            if (mp.find(i) == mp.end())
            {
                cnt++;
            }
        }
        cout << cnt + mp[x];
    }
    else
    {
        cout << mp[x];
    }
}