/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

bool binarysearch(vector<int> &a, int l, int h, int k)
{

    if (l > h)
    {
        return false;
    }
    int mid = l + (h - l) / 2;

    if (a[mid] == k)
    {
        return true;
    }
    else if (a[mid] < k)
    {
        return binarysearch(a, mid + 1, h, k);
    }
    else if (a[mid] > k)
    {
        return binarysearch(a, l, mid - 1, k);
    }
    // return false;
}

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

        cout << (binarysearch(a, 0, n - 1, k) ? "Found" : "Not found");
    }

    return 0;
}