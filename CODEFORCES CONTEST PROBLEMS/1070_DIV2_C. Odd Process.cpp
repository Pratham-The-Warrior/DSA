#include <bits/stdc++.h>
using namespace std;
#define int long long

void testcase()
{
    // code here
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> odd;
    vector<int> even;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] % 2 == 0)
        {
            even.push_back(arr[i]);
        }
        else
        {
            odd.push_back(arr[i]);
        }
    }
    sort(odd.rbegin(), odd.rend());
    sort(even.rbegin(), even.rend());
    vector<int> evenpf((int)even.size(), 0);
    if (even.size() > 0)
    {
        evenpf[0] = even[0];
    }
    for (int i = 1; i < even.size(); i++)
    {
        evenpf[i] = evenpf[i - 1] + even[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        int evencnt = even.size();
        int oddcnt = odd.size();
        if (oddcnt == 0)
        {
            cout << 0 << " ";
            continue;
        }
        if (evencnt == 0)
        {
            if (i % 2 == 0)
            {
                cout << 0 << " ";
            }
            else
            {
                cout << odd[0] << " ";
            }
        }
        else if (i == 1)
        {
            cout << odd[0] << " ";
        }
        else if (evencnt + 1 >= i)
        {
            if (evencnt == 0)
            {
                cout << odd[0] << " ";
            }
            else
            {
                cout << evenpf[i - 2] + odd[0] << " ";
            }
        }
        else
        {
            int oddeff = i - evencnt;
            if (oddeff % 2 == 0)
            {
                if (oddeff < oddcnt)
                {
                    if (evencnt - 2 < 0)
                    {
                        cout << odd[0] << " ";
                    }
                    else
                        cout << evenpf[evencnt - 2] + odd[0] << " ";
                }
                else
                {
                    cout << 0 << " ";
                }
            }
            else
            {
                if (evencnt == 0)
                {
                    cout << odd[0] << " ";
                    continue;
                }
                cout << evenpf[evencnt - 1] + odd[0] << " ";
            }
        }
    }
    cout << "\n";
}

signed main()
{
    int t = 1;
    cin >> t; // comment this line if only one testcase
    while (t--)
    {
        testcase();
    }
    return 0;
}