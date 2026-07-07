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

        long long int ans = 0;

        for (int i = 1; i <= n; i++)
        {

            ans += 1LL * (n / i) * (n / i);
        }

        cout << ans << "\n";
    }

    return 0;
}