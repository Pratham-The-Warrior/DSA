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

    int t;
    cin >> t;
    while (t--)
    {
        // Your code here

        int n;
        cin >> n;
        vector<ll> a(n);
        map<ll, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]]++;
        }

        int maxi = 0, num = 0;

        for (auto x : mp)
        {
            if (x.second > maxi)
            {
                maxi = x.second;
                num = x.first;
            }
        }

        ll non_num = n - maxi;

        ll temp = maxi;

        ll ops = 0;

        while (non_num > 0)
        {
            non_num -= temp;
            temp *= 2;
            ops++;
        }

        cout << ops + n - maxi << endl;
    }

    return 0;
}