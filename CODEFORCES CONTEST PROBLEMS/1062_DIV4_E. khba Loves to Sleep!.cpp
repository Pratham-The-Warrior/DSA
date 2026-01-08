#include <bits/stdc++.h>
using namespace std;
#define int long long

// Problem Statement
/*
    u have n friends. k teleports must be placed..

    [0, x]

        distinct k teleports , name them t

        such that..

            min(|ai - tj|) is maximised.


            So, if u look at above value..

            ans > z means ??

            <=>
             for all i,

                u cannot place in [ai - z, ai + z]..

                any teleport here.

                So, the number of positions after u remove such things ok !!

                the number of positions left if its >= k..

                then ans > z.

                how do u take them,,
                maybe greedily take them..

                start from 0, find next friend. skip ai - z to ai + z..
                and then find next friend and so on...





*/

// Small Observatins
/*

*/

/*

*/

// Claims on algo
/*


*/

#define N 200010

int a[N];
vector<int> ans;

int n, k, x;
bool check(int z)
{
    ans.clear();
    int y = 0, j = 0; // j points to something >= y

    // [a[j] - z, a[j] + z]

    while (y <= x && ans.size() < k)
    {

        while (a[j] - z <= y)
        {
            j++; // ta max n
        }
        // a[j - 1] - z <= y
        if (j == 0 || (y > a[j - 1] + z))
        {
            ans.push_back(y); // at max k pushes..
            y++;
        }
        else
        {
            y = a[j - 1] + z + 1; // at max n jumps
        }
    }

    // cout << y << '\n';

    // cout << ans.size() << '\n';

    // cout << '\n';
    return ans.size() >= k;
}

void solve()
{
    cin >> n >> k >> x;

    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    a[n] = 2e9 + 10;

    // ans > z or not is given by check

    int left = -1, right = x + 1;

    while (left != right - 1)
    {
        int mid = (left + right) / 2;
        if (check(mid))
            left = mid;
        else
            right = mid;
    }

    // cout << right << '\n';
    check(left);
    for (int i : ans)
        cout << i << ' ';
    cout << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

// Golden Rules
/*
    Solutions are simple.

    Proofs are simple.

    Implementations are simple.
*/
