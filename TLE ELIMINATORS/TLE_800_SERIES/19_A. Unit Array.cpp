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
        int n;
        cin >> n;
        vector<int> a(n);
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }

        int ct = count(a.begin(), a.end(), -1);

        if (sum >= 0 && ct % 2 == 0)
        {
            cout << 0 << endl;
            continue;
        }

        if (sum >= 0 && ct % 2 != 0)
        {
            cout << 1 << endl;
            continue;
        }

        // Case 3  sum < 0 → need flips to make sum >= 0
        int to_remove = (-sum + 1) / 2; // minimum flips to make sum non-negative
        ct -= to_remove;                // remaining -1 after fixing sum
        if (ct % 2 != 0)
            to_remove++; // fix product if needed
        cout << to_remove << endl;
    }

    return 0;
}
