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
    vector<int> coins(n);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
        sum += coins[i];
    }

    vector<bool> dp(sum + 1, false);

    dp[0] = true;

    for (auto coin : coins)
    {
        for (int i = sum; i >= coin; i--)
        {
            if (dp[i - coin] == true)
            {
                dp[i] = true;
            }
        }
    }

    vector<int> ans;

    for (int i = 1; i <= sum; i++)
    {
        if (dp[i])
        {
            ans.push_back(i);
        }
    }

    cout << ans.size() << endl;
    for (auto x : ans)
        cout << x << " ";

    return 0;
}

//* ---------------------------------------------------------------------------*/

// bitset optimization

/*

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> coins(n);
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
        sum += coins[i];
    }

    bitset<100001> dp;  // max possible sum = 100 * 1000 = 100000 //*vector<bool> dp(100001);
    dp[0] = 1;

    for (auto coin : coins)
    {
        dp |= (dp << coin);
    }

    vector<int> ans;

    for (int i = 1; i <= sum; i++)
    {
        if (dp[i])
        {
            ans.push_back(i);
        }
    }

    cout << ans.size() << "\n";
    for (auto x : ans)
        cout << x << " ";

    return 0;
}










*/