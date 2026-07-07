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

    int n;
    cin >> n;
    vector<ll> coins(n);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    sort(coins.begin(), coins.end());

    long long reach = 0;

    for (auto coin : coins)
    {
        if (coin > reach + 1)
        {
            cout << reach + 1 << "\n";
            return 0;
        }
        reach += coin;
    }

    cout << reach + 1 << "\n";

    return 0;
}

/*
1 2 2 7 9

1 2 3 7 8

1 2 3

1 5

1


*/