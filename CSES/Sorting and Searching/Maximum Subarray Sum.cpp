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
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // kadane will work here

    ll ans = LLONG_MIN, curr_sum = 0;

    for (int i = 0; i < n; i++)
    {
        curr_sum += a[i];
        ans = max(ans, curr_sum);

        if (curr_sum < 0)
        {
            curr_sum = 0;
        }
    }

    cout << ans;
    return 0;
}

/*----------------------------------------------------------------------- */
//*VARIATION 1
//*Maximum Subarray Sum with At Most K Deletions

//*dp[j] = maximum subarray sum ending at current index with at most j deletions used
