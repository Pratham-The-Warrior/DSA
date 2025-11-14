/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

vector<int> greedyCoinSelection(vector<int> coins, int V)
{

    sort(coins.rbegin(), coins.rend());

    vector<int> used;

    for (int coin : coins)
    {
        while (V >= coin)
        {
            V -= coin;
            used.push_back(coin);
        }
    }

    return used;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, v;
        cin >> n >> v;
        vector<int> coins(n);
        for (int i = 0; i < n; i++)
        {
            cin >> coins[i];
        }
        vector<int> ans = greedyCoinSelection(coins, v);

        for (auto x : ans)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}