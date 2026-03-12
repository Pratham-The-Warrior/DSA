/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<bool> good(n);
    vector<vector<int>> adj(n);

    for (int i = 0; i < n; i++)
    {
        int par, type;
        cin >> par >> type;
        if (type == 0)
            good[i] = true;
        if (par != -1)
        {
            adj[par - 1].push_back(i); // zero based
        }
    }

    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        if (good[i])
            continue;
        bool flag = true;
        for (auto x : adj[i])
        {
            if (good[x])
                flag = false;
        }
        if (flag)
            ans.push_back(i + 1); // if all children are false
    }

    // sort(ans.begin(), ans.end());

    if (ans.size())
    {
        for (auto x : ans)
            cout << x << " ";
    }
    else
    {
        cout << -1 << endl;
    }

    cout << endl;

    return 0;
}