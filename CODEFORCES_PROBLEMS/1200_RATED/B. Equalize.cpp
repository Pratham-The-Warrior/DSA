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
        vector<int> a(n), b;
        set<int> s;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            s.insert(a[i]);
        }
        for (auto x : s)
        {
            b.push_back(x);
        }

        sort(b.begin(), b.end());

        int i = 0, j = 0;
        int cnt = 0;

        while (j < b.size())
        {
            if (b[j] - b[i] < n)
            {
                j++;
            }
            else
            {
                i++;
            }
            cnt = max(cnt, j - i);
        }
        cout << cnt << endl;
    }

    return 0;
}