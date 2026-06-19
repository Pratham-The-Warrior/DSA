/*-------------------------------------------------------------
   NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
---------------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }

    bool possible = true;

    while (!mp.empty())
    {
        auto it = mp.begin();
        int num = it->first;
        int count = it->second;
        mp.erase(it);

        // 2 copies to pair up (one for Bag 1, one for Bag 2)
        count -= 2;

        if (count < 0)
        {
            // only 1 prsent not possible
            possible = false;
            break;
        }

        //
        if (count > 0)
        {
            mp[num + 1] += count;
        }
    }

    if (possible)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}