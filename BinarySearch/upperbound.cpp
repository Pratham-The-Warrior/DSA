#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int l = 0, h = n - 1;

        while (l < h)
        {
            int mid = l + (h - l) / 2;

            if (a[mid] <= k)
            {
                l = mid + 1;
            }
            else
            {
                h = mid;
            }
        }

        cout << "The number is => " << a[l] << endl;
    }
    return 0;
}
