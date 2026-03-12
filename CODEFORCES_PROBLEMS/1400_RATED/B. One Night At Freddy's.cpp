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

    int t;
    cin >> t;
    while (t--)
    {
        int n, m, l;
        cin >> n >> m >> l;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        multiset<int> s;

        for (int i = 0; i < min(n + 1, m); i++)
        {
            s.insert(0);
        }

        int ans = l;
        int left = n;

        for (int i = 1; i <= l; i++)
        {
            auto it = s.begin(); /*Find the smallest value in the multiset (*s.begin()).

 Increment it by 1.

 Re-insert it.
 This "fills" the slots in a Round-Robin fashion, keeping their values nearly equal.*/
            int val = *it + 1;
            s.erase(it);
            s.insert(val);

            if (binary_search(a.begin(), a.end(), i))
            {
                auto it = prev(s.end()); // Get the largest value
                int val = *it;
                s.erase(it); // Terminate this process
                ans -= val;  // Subtract its "cost" from the total
                if (int(s.size()) < left)
                {
                    s.insert(0); // Start a new process if needed
                }
                left -= 1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}